#include "clock.h"
extern struct CLOCK g_clock;
struct P { char pad[0x30]; int state; float tState; };
void func_001EF038(struct P *p);
void func_001EEFC0(struct P *p);
void func_00146E18(struct P *p, int state)
{
    if (state == p->state) return;
    switch (p->state) {
    case 2: case 3: case 4:
        func_001EF038(p);
    }
    p->state = state;
    p->tState = g_clock.t;
    switch (state) {
    case 2: case 3: case 4:
        func_001EEFC0(p);
    }
}
