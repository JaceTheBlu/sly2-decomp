#include "vtable.h"
struct O { char pad[0xC]; struct VTE *pvt; };
struct B { float min[4]; float max[4]; char pad[0x60 - 0x20]; struct O *po; };
int func_00134310(int a, int b);
static __inline__ int Call(struct O *po, struct O *poOther)
{
    return ((int (*)(void *, struct O *))po->pvt[61].pfn)((char *)po + po->pvt[61].delta, poOther);
}
int func_00133D08(void *unused, struct B *pa, struct B *pb)
{
    int n1, n2, r;
    if (pa->min[0] >= pb->max[0] || pa->min[1] >= pb->max[1] || pa->min[2] >= pb->max[2] ||
        pb->min[0] >= pa->max[0] || pb->min[1] >= pa->max[1] || pb->min[2] >= pa->max[2])
        return 0;
    n1 = Call(pa->po, pb->po);
    n2 = Call(pb->po, pa->po);
    r = func_00134310(n1, n2);
    return r != 1 && r != 3;
}
