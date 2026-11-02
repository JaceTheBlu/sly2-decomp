#include "clock.h"
struct X { int a; int b; int c; };
struct E { int a[4]; };
struct S { char pad[0x180]; int x180; int x184; char p1[0x38]; int n; float t; char p2[0x48]; struct X x; int p3; struct E ae[1]; };
extern struct CLOCK g_clock;
static __inline__ void ClearX(struct X *px) { px->a = px->b = px->c = 0; }
void func_0017F4C0(struct S *p, struct E *pe);
void func_00181268(struct S *p, int n)
{
    if (p->n == n) return;
    if (p->n == -1) p->x184 = p->x180;
    p->n = n;
    p->t = g_clock.t;
    switch (n) {
    case 0: case 1: case 2: case 4:
        ClearX(&p->x);
        break;
    case 3:
        break;
    }
    func_0017F4C0(p, n == -1 ? 0 : &p->ae[n]);
}
