#include "clock.h"
struct VTE { short d; short pad; void (*pfn)(void *); };
struct O { char pad[0xC]; struct VTE *vt; };
struct S { char pad[0x54]; int n; float t; char pad2[0x78 - 0x5C]; float dt; char pad3[4]; struct O *po; };
extern struct CLOCK g_clock;
extern int D_003E0F9C;
void func_001A5E28(struct S *p);
void func_00165118(struct S *p, int n);
void func_00163B48(struct S *p)
{
    struct O *po;
    func_001A5E28(p);
    if (p->n == 1 && p->dt > 0.0f) {
        float dt = g_clock.t - p->t;
        if (dt < p->dt && p->dt + g_clock.dt <= dt)
            func_00165118(p, 0);
    }
    po = p->po;
    if (po) {
        int f = p->n == 1; if (D_003E0F9C) f = 0;
        if (f) {
            struct VTE *e = &po->vt[8];
            e->pfn((char *)po + e->d);
        } else {
            struct VTE *e = &po->vt[9];
            e->pfn((char *)po + e->d);
        }
    }
}
