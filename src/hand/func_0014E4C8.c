#include "clock.h"
/* Matched by Claude agent (2026-10-17): compare against the parameters directly (no local E copy) and `for (i = 0, pe = p->ae; ...)`. */
struct VTE { short d; short pad; void (*pfn)(void *, ...); };
struct O { int pad[3]; struct VTE *vt; };
struct E { int prio; struct O *po; int a; int b; };
struct P { char pad[0x30C]; int c; struct E ae[8]; char pad2[0x390 - 0x390]; float t; };
extern struct CLOCK g_clock;
void func_0014E4C8(struct P *p, int grf, int prio, struct O *po, int a, int b)
{
    struct E *peOut;
    struct E *pe;
    int i;
    struct O *poTop;
    int aTop;
    int bTop;
    poTop = 0;
    aTop = 0;
    bTop = 0;
    peOut = p->ae;
    for (i = 0, pe = p->ae; i < p->c; i++, pe++) {
        if ((((grf ^ 1) & 1) || prio == pe->prio) &&
            (!(grf & 2) || po == pe->po) &&
            (!(grf & 4) || a == pe->a) &&
            (!(grf & 8) || b == pe->b)) {
            if (i == 0) {
                poTop = pe->po;
                aTop = pe->a;
                bTop = pe->b;
            }
            {
                struct O *o = pe->po;
                struct VTE *v = &o->vt[5];
                ((void (*)(void *, int))v->pfn)((char *)o + v->d, pe->b);
            }
        } else {
            *peOut++ = *pe;
        }
    }
    p->c = peOut - p->ae;
    if (poTop) {
        struct VTE *v = &poTop->vt[3];
        ((void (*)(void *, int, int))v->pfn)((char *)poTop + v->d, aTop, bTop);
    if (p->c > 0) {
        struct O *o;
        struct VTE *v;
        p->t = g_clock.t;
        o = p->ae[0].po;
        v = &o->vt[2];
        ((void (*)(void *, int, int))v->pfn)((char *)o + v->d, p->ae[0].a, p->ae[0].b);
    }
    }
}
