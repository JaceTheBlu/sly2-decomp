typedef int qword __attribute__((mode(TI)));
extern qword D_002A2DD0;
struct MK { int a[4]; };
struct AI { int cb; int align; };
struct S { char pad[0x50]; int c50; void *p54; char pad2[0x94 - 0x58]; void *p94; int c98; void *p9C; };
struct MK *func_001AE478(struct MK *pm);
void _$_18CBinaryInputStream(struct MK *pm, int n);
void *func_001AE378(struct AI *pa);
void *func_001AE318(struct AI *pa);
void *func_001AE238(struct AI *pa, void *pv);
void func_001733C8(struct S *p, qword q);
void func_001A5C28(struct S *p, void *pv);
static inline struct AI *SetAi(struct AI *pa, int cb, int align) { pa->cb = cb; pa->align = align; return pa; }
void func_001731B8(struct S *p, void *pv) {
    struct MK mk;
    struct AI ai;
    func_001AE478(&mk);
    p->p54 = func_001AE378(SetAi(&ai, 0xE00, 0x10));
    p->p9C = func_001AE318(SetAi(&ai, 0x100, 0x10));
    p->p94 = func_001AE318(SetAi(&ai, 0x20, 0x10));
    func_001733C8(p, D_002A2DD0);
    func_001A5C28(p, pv);
    p->p54 = func_001AE238(SetAi(&ai, p->c50 * 0x1C, 0x10), p->p54);
    { void *pv9C = func_001AE238(SetAi(&ai, p->c98 << 4, 0x10), p->p9C); void *pv94 = p->p94; p->p9C = pv9C; p->p94 = func_001AE238(SetAi(&ai, 0x20, 0x10), pv94); }
    _$_18CBinaryInputStream(&mk, 2);
}
