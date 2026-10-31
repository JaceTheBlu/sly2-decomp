#include "clock.h"
struct VTE { short d; short pad; void (*pfn)(void *, int); };
struct O { char pad[0xC]; struct VTE *vt; char pad2[0x8C - 0x10]; int f8c; };
struct S { char pad[0x3BC4]; struct O *po; char pad2[0x476C - 0x3BC8]; float t; };
extern struct CLOCK g_clock;
void func_001618F8(struct S *p, float dt)
{
    struct O *po = p->po;
    if (po) {
        struct VTE *e;
        po->f8c = 0;
        e = &po->vt[49];
        e->pfn((char *)po + e->d, -1);
    }
    p->t = g_clock.t + dt;
}
