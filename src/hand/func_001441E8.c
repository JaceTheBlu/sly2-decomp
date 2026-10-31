#include "clock.h"
/* only diff: hazard nop placement (target: no nop after mfc1 before beqz, nop after mtc1); assembler-level */
extern struct CLOCK g_clock;
int func_001441A0(void *p);
void func_001441C0(void *p, int n);
struct P { char pad[0x1308]; float g; };
void func_001441E8(struct P *p, float f)
{
    int n;
    p->g += f * g_clock.dt;
    n = (int)p->g;
    if (n) {
        int x;
        p->g -= (float)n;
        x = func_001441A0(p) - n;
        func_001441C0(p, x > -1 ? x : 0);
    }
}
