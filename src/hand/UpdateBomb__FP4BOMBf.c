#include "vtable.h"
#include "clock.h"
typedef int qword __attribute__((mode(TI)));
struct P { char pad[0xC]; struct VTE *pvt; char pad2[0x154 - 0x10]; float t154; float g158; char pad3[0x1F4 - 0x15C]; int f1F4; };
extern struct CLOCK g_clock;
void UpdateSo__FP2SOf(struct P *p);
void func_0013B860(struct P *p);
void func_0013AC18(struct P *p);
static __inline__ float GLength(qword v)
{
    qword d, t;
    float g;
    __asm__("vmul.xyz %0, %1, %1\n"
        "vaddw.x %2, $vf0, $vf0w\n"
        "vadday.x ACC, %0, %0y\n"
        "vmaddz.x %0, %2, %0z" : "=j"(d), "+j"(v), "=j"(t));
    __asm__("vsqrt Q, %0x\n"
        "vwaitq\n"
        "vaddq.x %0, $vf0, Q" : "+j"(d));
    __asm__("qmfc2.ni %0, %1" : "=r"(g) : "j"(d));
    return g;
}
void UpdateBomb__FP4BOMBf(struct P *p)
{
    UpdateSo__FP2SOf(p);
    if (p->t154 <= g_clock.t)
        goto out;
    {
        struct VTE *vt = p->pvt;
        qword v = ((qword (*)(void *))vt[33].pfn)((char *)p + vt[33].delta);
        int f = GLength(v) < p->g158;
        if (f) {
        out:
            func_0013B860(p);
        } else if (p->f1F4) {
            func_0013AC18(p);
        }
    }
}
