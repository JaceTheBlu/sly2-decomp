#include "clock.h"
typedef int qword __attribute__((mode(TI)));
extern struct CLOCK g_clock;
struct VTE { short d; short pad; void (*pfn)(void *); };
struct O { char pad[0xC]; struct VTE *vt; };
struct X { char pad[0x14]; int n14; float g18; };
struct E { struct O *po; int pad; float g8; struct X *px; int k; int pad2[3]; qword q; };
struct S { char pad[0x58]; int c58; char pad2[0xA0 - 0x5C]; float gA0; float gA4; };
qword func_00173A18(struct S *p);
void func_00173928(struct S *p, struct E *pe, int k, int f) {
    pe->k = k;
    switch (k) {
    case 0:
        { struct O *o = pe->po; struct VTE *e; pe->g8 = g_clock.t; e = &o->vt[9]; e->pfn((char *)o + e->d); }
        if ((f ^ 1) & 1) pe->px->g18 = g_clock.t;
        break;
    case 1:
        pe->g8 = g_clock.t + p->gA0;
        pe->q = func_00173A18(p);
        if ((f ^ 1) & 1) pe->px->g18 = g_clock.t + p->gA4;
        break;
    }
    pe->po = 0;
    pe->px->n14 = 0;
    pe->px = 0;
    p->c58--;
}
