#include "clock.h"
struct H { char pad[0xFD50]; int x; };
extern struct H D_002E65E0;
extern struct CLOCK g_clock;
struct S { char pad[0x44]; int x44; float x48; };
void func_001ACC38(struct S *p, int n)
{
    if (n == p->x44) return;
    switch (n) { case 2: case 3: D_002E65E0.x = 0; }
    p->x44 = n;
    p->x48 = g_clock.tFrame;
}
