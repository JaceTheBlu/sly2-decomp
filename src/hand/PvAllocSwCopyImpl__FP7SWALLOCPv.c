struct MSG { int cb; int nKind; };
void *PvAllocSwImpl__Fi(struct MSG *pm);
void func_001AE5A0(void *, void *, int);
void *PvAllocSwCopyImpl__FP7SWALLOCPv(struct MSG *pm, void *pvSrc)
{
    struct MSG m = *pm;
    void *p = PvAllocSwImpl__Fi(&m);
    if (p) func_001AE5A0(p, pvSrc, pm->cb);
    return p;
}
