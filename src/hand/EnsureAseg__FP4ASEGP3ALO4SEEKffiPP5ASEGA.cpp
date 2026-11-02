struct ASEG; struct ALO; struct ASEGA;
enum SEEK { SEEK_0 };
ASEGA *PasegaFindAseg(ASEG *paseg, ALO *palo);
void ApplyAseg(ASEG *paseg, ALO *paloRoot, float t, float svt, int grfapl, ASEGA **ppasega);
void SeekAsega(ASEGA *pasega, SEEK seek, float t, float svt);   /* SeekAsega__FP5ASEGA4SEEKff */
void EnsureAseg(ASEG *paseg, ALO *paloRoot, SEEK seek, float t, float svt, int grfapl, ASEGA **ppasega)
{
    ASEGA *pasega;
    if (!ppasega) ppasega = &pasega;
    pasega = PasegaFindAseg(paseg, paloRoot);
    if (pasega) *ppasega = pasega;
    else ApplyAseg(paseg, paloRoot, 0.0f, 1.0f, grfapl, ppasega);
    SeekAsega(*ppasega, seek, t, svt);
}
