#include "clock.h"
extern struct CLOCK g_clock;
struct S { int a; float t; int n; };
void func_0020A9A8(struct S *p, int n) { p->t = g_clock.t; p->n = n; }
