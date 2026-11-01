#include "vtable.h"
struct O { int x0, x4, x8; struct VTE *vt; };
void func_001A6450(struct O *o, void *arg)
{
    struct O **list;
    int n, i;
    struct VTE *e = &o->vt[0xE0 / 8];
    n = ((int (*)(void *, struct O ***))e->pfn)((char *)o + e->delta, &list);
    for (i = 0; i < n; i++) {
        struct O *p = list[i];
        struct VTE *f = &p->vt[0x128 / 8];
        ((void (*)(void *, void *))f->pfn)((char *)p + f->delta, arg);
    }
}
