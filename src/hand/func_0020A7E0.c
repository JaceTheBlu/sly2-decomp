#include "clock.h"
extern struct CLOCK g_clock;
extern float D_002C3DB4;
struct S { int a; float t; };
int func_0020A7E0(struct S *p) { return g_clock.t - p->t > D_002C3DB4; }
