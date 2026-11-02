#include "clock.h"
extern struct CLOCK g_clock;
struct O { char pad[0xFBC]; int xfbc; };
struct S { char pad[0x4748]; int x4748; float x474c; };
int func_0015E9C8(struct S *, int, int, int, int, struct O **);
void func_00207030(struct O *, int);
void func_0019F170(struct S *p, int f) {
    struct O *ap[32];
    int c, i;
    p->x4748 = f;
    p->x474c = g_clock.t;
    c = func_0015E9C8(p, 0x105, 0x38, 0, 32, ap);
    for (i = 0; i < c; i++) {
        if (f) func_00207030(ap[i], 0xE);
        else if (ap[i]->xfbc == 0xE) func_00207030(ap[i], -1);
    }
}
