#include "clock.h"
struct S { char pad[0x4CC]; int x4cc; char p1[0xA80]; char xf50[4]; int xf54; char p2[0x970]; int n; char p3[0x1D8]; float t; };
extern struct CLOCK g_clock;
void func_00141640(struct S *p, int *pf);
void func_0019EA00(void *p, int *pf);
void func_0018A428(struct S *p, int *pf)
{
    if (p->n != 0 && p->n != 0x12 && p->x4cc && p->xf54 != 1)
        p->t = g_clock.t;
    func_00141640(p, pf);
    switch (p->n) {
    case 8:
        func_0019EA00(p->xf50, pf);
        break;
    case 3: case 5: case 6:
        *pf |= 1;
        break;
    }
}
