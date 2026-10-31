#include "clock.h"
extern struct CLOCK g_clock;
struct P { char pad[0x90]; int state; float tState; };
void func_001487A0(struct P *p);
void func_00148860(struct P *p);
void func_00148A78(struct P *p, int state)
{
    int f1, f2; int old = p->state; if (old == state) return; f1 = old == 0 && state == 1; f2 = old != -1 && state == 0;
    p->state = state;
    p->tState = g_clock.t;
    if (f1) func_001487A0(p);
    if (f2) func_00148860(p);
}
