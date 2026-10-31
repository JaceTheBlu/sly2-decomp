struct MSG { int cb; int nKind; };
void *PvAllocSwImpl__Fi(struct MSG *pm);
void func_002333B4(void *p, int c, int n);
void *func_001AE2A0(struct MSG *pm)
{
    struct MSG m = *pm;
    void *p = PvAllocSwImpl__Fi(&m);
    if (p) func_002333B4(p, 0, pm->cb);
    return p;
}
