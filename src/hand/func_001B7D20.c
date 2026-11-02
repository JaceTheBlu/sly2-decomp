#include "clock.h"
extern struct CLOCK g_clock;
extern char g_sw[];
struct VE { short d; short pad; void (*pfn)(); };
struct X { char pad[0x58]; int x58; int x5C; };
struct O { char pad[0xC]; struct VE *vt; char pad1[0x180 - 0x10]; struct X *x180; };
struct P { char pad[0x13F0]; struct O *x13F0; int a13F4[4]; int x1404; int x1408; char pad2[0x1430 - 0x140C]; struct X *x1430; float f1434; char pad3[0x1600 - 0x1438]; int a1600[4]; int x1610, x1614; int a1618[4]; };
void func_0012E460(int *p);
void func_002303A0(struct X *x, int a, int b);
void func_001F6860(struct X *x, int a);
void SetLoParent__FP2LOP2SOi(struct X *x, int a, int b);
void func_00134320(void *g, struct P *p);
void func_001B7D20(struct P *p)
{
    struct O *o;
    struct X *x;
    func_0012E460(&p->a13F4[0]);
    func_0012E460(&p->a13F4[1]);
    func_0012E460(&p->a13F4[2]);
    func_0012E460(&p->a13F4[3]);
    func_0012E460(&p->a1600[0]);
    func_0012E460(&p->a1600[1]);
    func_0012E460(&p->a1600[2]);
    func_0012E460(&p->a1600[3]);
    func_0012E460(&p->a1618[0]);
    func_0012E460(&p->a1618[1]);
    func_0012E460(&p->a1618[2]);
    func_0012E460(&p->a1618[3]);
    o = p->x13F0;
    if (!o) return;
    ((void (*)())o->vt[3].pfn)((char *)o + o->vt[3].d, 6, 0, 0, 0, 0);
    x = p->x13F0->x180;
    func_002303A0(x, x->x58, p->x1404);
    func_002303A0(x, x->x5C, p->x1408);
    func_001F6860(x, 0);
    SetLoParent__FP2LOP2SOi(x, 0, 0xF);
    p->x1430 = x;
    p->f1434 = g_clock.t;
    func_00134320(g_sw, p);
}
