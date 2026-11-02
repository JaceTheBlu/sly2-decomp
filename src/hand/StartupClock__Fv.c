#include "clock.h"
extern struct CLOCK g_clock;
unsigned long TickNow__FP5CLOCK(struct CLOCK *p);
void func_0014D068(struct CLOCK *p);
void StartupClock__Fv(void)
{
    unsigned long c[2];
    unsigned int i;
    float *pf;
    __asm__ volatile ("mfc0 %0, $9" : "=r"(c[0]));
    g_clock.tickRaw = c[0];
    g_clock.tickFrame = TickNow__FP5CLOCK(&g_clock);
    for (i = 0; i < 9; i++) g_clock.art[i] = 1.0f;
    g_clock.rt = 1.0f;
    g_clock.rtReal = 1.0f;
    func_0014D068(&g_clock);
}
