struct O { char pad[0x148]; long fl; };
struct A { int pad; struct O *po; };
struct M { int cb; int align; int pad[2]; };
void *PvAllocStackImpl__FP7SWALLOC(struct M *pm);
void func_0020FDC8(int n, struct A **apa, int *pc, struct O ***pppo)
{
    struct M m;
    struct O **apo;
    int c = 0;
    int i;
    m.cb = n * 4;
    m.align = 0x10;
    apo = (struct O **)PvAllocStackImpl__FP7SWALLOC(&m);
    for (i = 0; i < n; i++) {
        struct O *po = apa[i]->po;
        if (!(po->fl & 0x40000000)) {
            po->fl |= 0x40000000;
            apo[c++] = po;
        }
    }
    for (i = 0; i < c; i++)
        apo[i]->fl &= ~0x40000000L;
    *pc = c;
    *pppo = apo;
}
