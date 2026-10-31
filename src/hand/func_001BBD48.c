struct MSG { int cb; int nKind; };
struct I { int a, b; };
struct S;
struct I *func_001BBDB0(struct S *p, int x);
void *PvAllocStackImpl__FP7SWALLOC(struct MSG *pmsg);
static __inline__ void *PvAllocMsg(struct MSG *pmsg, int cb, int nKind) { pmsg->cb = cb; pmsg->nKind = nKind; return PvAllocStackImpl__FP7SWALLOC(pmsg); }
void func_001BBD48(struct S *p, int a, int b)
{
    struct MSG msg;
    struct I *pi = func_001BBDB0(p, 0xC);
    pi->b = (int)PvAllocMsg(&msg, 8, 0x10);
    ((int *)pi->b)[0] = a;
    ((int *)pi->b)[1] = b;
}
