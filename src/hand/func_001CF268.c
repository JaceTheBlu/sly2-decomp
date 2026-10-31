#include "clock.h"
typedef int qword __attribute__((mode(TI)));
struct VTE { short d; short pad; void (*pf)(); };
extern struct CLOCK g_clock;
struct LO { char pad[0xC]; struct VTE *vt; char p1[0x28 - 0x10]; unsigned long x28; char p2[0xE8 - 0x30]; int xE8; };
struct G { char pad[0x150]; int x150; };
struct S { char pad[0x8]; struct G *pg; char p0[0x14 - 0xC]; float x14; float x18; char p1[0x70 - 0x1C]; qword x70;
    char p2[0xE0 - 0x80]; struct LO *xE0; char p3[0xEC - 0xE4]; struct VTE *vt; };
void func_001CE980(struct S *p);
void func_001CF268(struct S *p)
{
    struct LO *plo;
    int f;
    if (g_clock.t - p->x14 > p->x18) {
        func_001CE980(p);
        return;
    }
    if (p->pg->x150 == 1) return;
    plo = p->xE0;
    if (!plo) return;
    if (!plo->xE8) return;
    f = 0;
    if ((int)(plo->x28 >> 60) & 1)
        if (((int (*)(void *, qword))plo->vt[73].pf)((char *)plo + plo->vt[73].d, p->x70)) f = 1;
    ((void (*)(void *, int))p->vt[7].pf)((char *)p + p->vt[7].d, f);
}
