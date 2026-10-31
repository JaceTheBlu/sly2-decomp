#include "clock.h"
extern struct CLOCK g_clock;
struct DL { void *a, *b; int c; };
extern struct DL D_003E1444;
struct S { char pad[0xFF8]; float t; };
void func_001F3E00(struct S *p);
void func_0011A2E8(struct DL *pdl, void *pv);
void func_002079A0(struct S *p) { func_001F3E00(p); func_0011A2E8(&D_003E1444, p); p->t = g_clock.t; }
