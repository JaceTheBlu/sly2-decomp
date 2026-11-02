#include "clock.h"
extern struct CLOCK g_clock;
struct VTE { short d; short pad; void (*pfn)(void *); };
struct O { char pad[0xC]; struct VTE *vt; char pad2[0x28]; int n38; int n3C; char pad3[0xC0 - 0x40]; int nC0; };
struct S { char pad[0x10]; void *p10; int pad2; char a18[0x18]; int n30; float g34; int n38; };
void func_001EF0D8(void *p);
struct O *func_00205438(void *p, int n);
void func_0017E0E0(struct S *p);
void func_0017E278(struct S *p, int n) {
    if (n == p->n30) return;
    func_001EF0D8(p->a18);
    p->n30 = n;
    p->g34 = g_clock.t;
    switch (n) {
    case 0:
        { struct O *o = func_00205438(p->p10, 0x9D); struct VTE *e; o->n3C = 0xB; o->n38 = p->n38; e = &o->vt[8]; e->pfn((char *)o + e->d); }
        break;
    case 1:
        { struct O *o = func_00205438(p->p10, 0xBA); struct VTE *e; o->nC0 = 1; o->n38 = 0x1C; func_0017E0E0(p); e = &o->vt[8]; e->pfn((char *)o + e->d); }
        break;
    case 2:
        { struct O *o = func_00205438(p->p10, 0x9E); struct VTE *e; o->n3C = 1; e = &o->vt[8]; e->pfn((char *)o + e->d); }
        break;
    }
}
