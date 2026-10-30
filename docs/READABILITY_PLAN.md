# Plan : rendre le code de la décompilation lisible

Objectif : passer d'un code qui *matche* (6 662/6 662 fonctions identiques octet par octet) à un code qu'un
humain peut lire, comprendre et modifier, **sans jamais perdre un seul match**.

## 1. État des lieux (mesuré sur `be803ab`)

| Indicateur | Valeur | Commentaire |
|---|---|---|
| Fonctions | 6 662 | 100 % matchées |
| Noms réels (`config/functions.csv`) | ~719 fonctions (~13 % du code en octets) | le reste s'appelle `func_XXXXXXXX` |
| Symboles de données nommés | 0 | ~2 640 `D_XXXXXXXX` distincts référencés |
| `src/hand/` | 3 469 fichiers, 167 k lignes | une fonction par fichier, 3 258 encore en `func_` |
| `src/auto/` | 2 081 fichiers, 42 k lignes | sortie m2c brute (`M2C_UNK`, `s32 temp_v0`…) |
| `src/splicewrap/` | 373 fichiers, 6 k lignes | générés, propres, mais appellent des `func_` |
| `src/lib/` | 680 fichiers, 22 k lignes | SDK Sony — **hors périmètre** (déjà nommé, pas du code du jeu) |
| `src/P2/` | 5 fichiers, ~1 k lignes | le seul code déjà « propre » (`bis.cpp`, `heap.cpp`…) : c'est la cible |
| Fichiers qui déclarent leurs propres structs | ~3 200 | `struct S`, `struct O`, `struct P`… avec `char pad[…]`, 1 282 `struct S` différents |
| Fichiers avec champs `padXX[]` | ~2 470 | |
| Fichiers avec `M2C_FIELD`/`M2C_UNK` | ~910 | |
| Fichiers avec `__asm__` | ~790 (5 400 instructions asm) | une partie = vraies ops VU0, une partie = astuces d'allocation de registres |
| Commentaires d'historique (« Claude agent, lane G19… ») | ~1 900 lignes | bruit, pas de documentation |
| Taille des fonctions | 2 382 < 16 instr., 3 622 de 16–100, 770 de 100–500, 42 > 500 | |

Points structurants :

1. **Pas de headers partagés.** Chaque fichier redéclare localement les classes avec des pads. C'est le principal
   obstacle à la lisibilité, et le principal chantier.
2. **Le match est vérifié fonction par fonction** (`tools/matchtool.py check`, relocations comprises). Renommer un
   symbole ou changer un type est donc *vérifiable automatiquement* : c'est notre filet de sécurité.
3. **Sly 2 réutilise le moteur de Sly 1** (même conventions : `LO`, `ALO`, `SO`, `CRef`, `CLOCK`…). La décompilation
   de Sly 1 fournit des noms et des layouts de structures ; `tools/show.py` sait déjà exploiter une table
   `config/sly1_matches.csv` (absente du dépôt).
4. **Certaines astuces de matching sont irréductibles** (asm « allocation-only », ordre de déclaration forcé…). On ne
   les supprimera pas ; on les isolera et documentera.

## 2. Principes

- **Règle d'or : 6 662/6 662 après chaque commit.** Aucun changement n'est fusionné si `tools/progress.py` régresse.
- Travailler **par classe / sous-système**, pas par fichier : on définit `SO` une fois, puis on migre tous ses
  utilisateurs.
- Automatiser tout ce qui est mécanique (renommage, remplacement de structs locales, nettoyage de commentaires) ;
  réserver l'effort humain/agent à la compréhension.
- Mesurer la lisibilité comme on a mesuré le matching (voir §5).

## 3. Phases

### Phase 0 — Outillage et garde-fous (≈ 2 semaines)

| Tâche | Détail | Effort |
|---|---|---|
| 0.1 Vérification incrémentale | `tools/verify_changed.sh` : recompile/compare uniquement les fichiers modifiés depuis `main` ; à lancer avant chaque commit (hook git) | 1–2 j |
| 0.2 Outil de renommage | `tools/rename.py OLD NEW` : met à jour `functions.csv`, `symbol_addrs.txt`, sources, noms de fichiers, prototypes ; gère le mangling g++ 2.95 | 2–3 j |
| 0.3 Table des données | Créer les entrées `D_` dans `symbol_addrs.txt` (`type:data`, taille) pour pouvoir les nommer | 1–2 j |
| 0.4 Nettoyage des commentaires d'historique | Déplacer les lignes « lane / agent / history » vers `docs/match_log/` (ou les supprimer, git garde l'historique) ; ne garder que les commentaires qui expliquent *pourquoi* une astuce est nécessaire | 1–2 j (script + relecture) |
| 0.5 Métriques de lisibilité | Étendre `progress.py` : % fonctions nommées, % fichiers sans struct locale/pad/`M2C_`, nb d'asm non documentés ; second graphe | 2 j |
| 0.6 (option) Build lié complet | Linker un ELF complet et le comparer à l'original — utile plus tard pour la phase 5 | 1–2 sem. |

### Phase 1 — Récupération des noms (≈ 3–5 semaines)

Sources par ordre de rendement :

1. **Sly 1** : appariement des fonctions par similarité (structure du CFG, constantes, appels vers fonctions déjà
   nommées) avec `TheOnlyZac/sly1` ; régénérer `config/sly1_matches.csv`. Estimation : 30–50 % des fonctions moteur.
2. **Table Splice** : les 373 wrappers sont enregistrés avec leur nom de script (chaînes) → nomme les wrappers *et*
   les fonctions moteur qu'ils appellent.
3. **Vtables** : un nom de classe dans une vtable nomme toutes ses méthodes par slot (`InitSo`, `UpdateSo`…).
4. **Chaînes de debug / asserts / noms de fichiers**.
5. **Propagation** : appelants/appelés de fonctions nommées, conventions Sucker Punch (`PfnFromX`, `FFooBar` pour
   les booléens, `CFoo`, préfixes hongrois).
6. **Manuel** pour le reste, en priorité les plus appelées (`func_0011CCA8` : 1 497 références, `func_001A62E8` : 827…).

Variables globales `D_` : même démarche (Sly 1 + usage), en commençant par les ~200 plus référencées.

Objectif de sortie : ≥ 80 % des fonctions du jeu nommées (hors SDK), 100 % des 300 fonctions les plus appelées.

### Phase 2 — Headers partagés et types (≈ 3–5 mois, le gros du travail)

1. **Hiérarchie de classes** : reconstruire `LO → ALO → SO → PO → …` (et `CRef`, `CLOCK`, `VECTOR`, `MATRIX3/4`…)
   à partir de Sly 1, des vtables et des offsets observés dans les ~3 200 structs locales.
2. **Outil de consolidation** (≈ 1–2 sem.) : extraire toutes les structs locales, les regrouper par offsets
   accédés et par fonction propriétaire, détecter les conflits → une base « champ @ offset : nom, type, preuve ».
3. **Écriture de `include/` par sous-système** (`lo.h`, `alo.h`, `so.h`, `jt.h`, `cm.h`, `vec.h`, `mat.h`…).
4. **Migration** : pour chaque classe, remplacer les déclarations locales par `#include`, vérifier le match, et
   corriger les cas où une déclaration différente changeait le code généré (types `int`/`short`, `const`, ordre des
   membres, unions).
5. Ordre conseillé : types de base (vecteurs, matrices, `CLOCK`, `CRef`) → `LO`/`ALO`/`SO` (utilisés partout) →
   joueur/caméra → sous-systèmes de gameplay → rendu/VU.

Risque principal : un même pad déclaré `char` dans un fichier et `int` dans un autre peut faire bouger
l'allocation de registres. Le match par fichier détecte tout de suite ces cas ; prévoir 10–20 % de fichiers
« têtus » qui demandent de l'investigation.

### Phase 3 — Nettoyage fonction par fonction (≈ 4–8 mois, parallélisable)

Pour chaque fonction, une fois ses types disponibles :

- `src/auto/` : remplacer `M2C_FIELD(p, s32*, 0x48)` par `p->m_field`, `temp_v0` par des noms parlants,
  `s32` → types du jeu, boucles `goto` → `for/while` quand ça matche encore.
- `src/hand/` : supprimer les structs locales, renommer `S/O/P/E` en vraies classes, renommer les variables.
- Commentaires : une ligne de description par fonction non triviale ; documentation des astuces restantes.
- Les fichiers `.c` qui sont en réalité des méthodes C++ passent en `.cpp` avec mangling correct.

Effort indicatif par fonction (types déjà prêts) :

| Taille | Nb | Temps unitaire | Total |
|---|---|---|---|
| < 16 instructions | 2 382 | 5 min | ~200 h |
| 16–100 | 3 622 | 15 min | ~900 h |
| 100–500 | 770 | 1 h | ~770 h |
| > 500 | 42 | 4 h | ~170 h |
| **Total** | **6 816 entrées** | | **~2 000 h** |

### Phase 4 — Isoler les astuces de matching (≈ 3–4 semaines)

- Rassembler les vraies opérations VU0 (`vadd`, `vmul`, `vsqrt`, `qmtc2`…) dans un header d'intrinsèques nommées
  (`include/vu0.h`) : c'est vraisemblablement ce que faisait le code original.
- Les asm « allocation-only », les `register … asm("$s0")` et les ordres de déclaration forcés restent, mais
  derrière une macro explicite (`MATCH_HACK_KEEP_IN_GPR(x)`) et avec un commentaire d'une ligne.
- Objectif : 0 asm non documenté hors `vu0.h`.

### Phase 5 — Unités de compilation d'origine (≈ 1–2 mois, optionnel mais très utile)

Regrouper les fichiers « une fonction par fichier » en fichiers sources d'origine (`jt.cpp`, `alo.cpp`, `cm.cpp`…),
à la manière de `src/P2/`. Les frontières se déduisent de l'ordre dans le binaire, des pools de constantes
`.rodata` et des noms Sly 1. Demande le build lié (0.6) ou une extension de `matchtool` pour comparer plusieurs
fonctions par fichier, et attention : compiler plusieurs fonctions ensemble peut modifier l'inlining et l'ordre des
littéraux.

## 4. Estimation globale

| Phase | Effort (1 personne expérimentée, temps plein) |
|---|---|
| 0 Outillage | 2–4 semaines |
| 1 Noms | 3–5 semaines |
| 2 Headers / types | 3–5 mois |
| 3 Nettoyage par fonction | 4–8 mois (~2 000 h) |
| 4 Astuces asm | 3–4 semaines |
| 5 Unités de compilation (option) | 1–2 mois |
| **Total** | **≈ 12–20 mois-personne** (≈ 2 000–3 300 h) |

**Avec agents IA**, comme pour le matching (cf. `CREDITS.md`) : les phases 1, 3 et 4 se parallélisent très bien
(chaque fonction se vérifie seule). Les phases 0 et 2 restent séquentielles et demandent du jugement humain sur la
conception des headers. Ordre de grandeur réaliste : **4–7 mois calendaires** pour une personne qui pilote et relit
plusieurs agents, dont 2–3 mois sur la phase 2 qui reste le goulot.

Incertitudes principales :

- taux de noms récupérables depuis Sly 1 (30 % vs 60 % change la phase 1 du simple au double) ;
- proportion de fichiers qui cassent le match quand on passe aux headers partagés ;
- niveau de lisibilité visé : « noms + types partout » (≈ phases 0–3) vs « code source propre organisé en
  modules » (phases 0–5).

## 5. Jalons et indicateurs

| Jalon | Critère | Cible indicative |
|---|---|---|
| J1 | Outillage en place, commentaires d'historique nettoyés, métriques publiées | fin du mois 1 |
| J2 | 80 % des fonctions nommées, 300 fonctions les plus appelées 100 % nommées | mois 2 |
| J3 | Types de base + `LO/ALO/SO` en headers ; 50 % des fichiers sans struct locale | mois 4 |
| J4 | 0 `M2C_FIELD`, < 10 % de fichiers avec pads | mois 6 |
| J5 | 0 asm non documenté, chaque fonction non triviale commentée | fin |
| J6 (option) | Sources regroupées par unité de compilation d'origine | fin + 2 mois |

Chaque jalon : toujours 6 662/6 662 fonctions matchées.

## 6. Premières actions concrètes

1. `tools/verify_changed.sh` + hook pre-commit.
2. `tools/rename.py`.
3. Métriques de lisibilité dans `progress.py`.
4. Script de nettoyage des commentaires d'historique.
5. Régénérer `config/sly1_matches.csv` et appliquer automatiquement les noms à forte confiance.
6. Pilote de la phase 2 sur un petit sous-système (par ex. `CLOCK` + `VECTOR`/`MATRIX`) pour mesurer le vrai coût
   par classe et recaler l'estimation.
