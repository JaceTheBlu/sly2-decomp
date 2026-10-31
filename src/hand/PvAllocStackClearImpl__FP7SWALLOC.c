struct MSG { int cb; int nKind; };
void *PvAllocStackImpl__FP7SWALLOC(struct MSG *pm);
void func_002333B4(void *p, int c, int n);
void *PvAllocStackClearImpl__FP7SWALLOC(struct MSG *pm)
{
    struct MSG m = *pm;
    void *p = PvAllocStackImpl__FP7SWALLOC(&m);
    if (p) func_002333B4(p, 0, pm->cb);
    return p;
}
