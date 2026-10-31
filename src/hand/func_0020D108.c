#include "clock.h"
extern struct CLOCK g_clock;
struct F { int a[0x18]; };
struct S { int n0; int n; float t; };
void *func_002333B4(void *pv, int c, int cb);
void func_001F7598(struct F *pf);
void func_0020D108(struct S *p, int n)
{
    if (p->n == n) return;
    p->n = n;
    p->t = g_clock.t;
    if (n == 2) {
        struct F f;
        func_002333B4(&f, 0, sizeof f);
        f.a[3] = 0x4000;
        f.a[0] = p->n0;
        f.a[2] = p->n0;
        f.a[4] = 0;
        func_001F7598(&f);
    }
}
