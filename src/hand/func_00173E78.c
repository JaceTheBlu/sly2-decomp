#include "clock.h"
extern struct CLOCK g_clock;
extern float D_002BE5E0;
struct E { int n; float g4; float g8; int pad[9]; };
struct S { char pad[0x5C]; int c; struct E *ae; };
struct E *func_00173E78(struct S *p, int k) {
    float t4 = g_clock.t - D_002BE5E0;
    float t8 = g_clock.t;
    struct E *peBest = 0;
    struct E *pe;
    int i;
    for (i = 0; i < p->c; i++) {
        pe = &p->ae[i];
        if (pe->n != 0) {
            if (pe->n == k) continue;
            if (peBest && peBest->n == 0) continue;
            if (t4 <= pe->g4) continue;
            t4 = pe->g4;
        } else {
            if (t8 <= pe->g8) continue;
            t8 = pe->g8;
        }
        peBest = pe;
    }
    return peBest;
}
