#include "clock.h"
typedef unsigned long ulong;
extern char D_002DEB30[];
ulong TickNow__FP5CLOCK(struct CLOCK *p);
void func_00161478(void *p);
static __inline__ float GClamp(float g, float gMin, float gMax)
{
    float r;
    if (g < gMin) r = gMin;
    else if (gMax < g) r = gMax;
    else r = g;
    return r;
}
void MarkClockTick__FP5CLOCKi(struct CLOCK *p, int fPaused)
{
    ulong tick = TickNow__FP5CLOCK(p);
    float dt = GClamp((float)(tick - p->tickFrame) * 3.3908420e-9f, 1.0f / 60.0f, 1.0f / 30.0f);
    p->dtReal = dt * p->rtReal;
    p->tReal += p->dtReal;
    {
    float dt2 = dt * p->art[3];
    p->dtFrame = dt2;
    if (!fPaused) {
        p->dt = dt2 * p->rt;
        p->t += p->dt;
        func_00161478(D_002DEB30);
    }
    }
    p->tickFrame = tick;
    p->tFrame += p->dtFrame;
}
