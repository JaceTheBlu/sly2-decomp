#include "cref.h"
struct VE { short d; short pad; void (*pf)(void *, int); };
struct S { char pad[0xC]; struct VE *vt; char pad2[0xBC]; char xcc[4]; };
struct L { int a[4]; };
void func_002013D8(struct CRef *r, void *a, int b, int c, struct L *pl, void *d);
void func_00129EC8(struct CRef *r);
void func_00212828(struct S *p, void *a)
{
    struct CRef r;
    struct L l;
    func_002013D8(&r, a, 0x10, 0xA, &l, p->xcc);
    func_00129EC8(&r);
    p->vt[49].pf((char *)p + p->vt[49].d, -1);
}
