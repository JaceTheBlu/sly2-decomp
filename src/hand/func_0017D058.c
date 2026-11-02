#include "clock.h"
extern struct CLOCK g_clock;
struct VTE { short d; short pad; void (*pfn)(void *); };
struct O { char pad[0xC]; struct VTE *vt; char pad2[0x2C]; int n3C; };
struct S { char pad[0x10]; void *p10; int pad2; char a18[0x18]; int n30; float g34; int pad3; int n3C; };
void func_001EF0D8(void *p);
struct O *func_00205438(void *p, int n);
void func_0017D058(struct S *p, int n) {
    if (n == p->n30) return;
    func_001EF0D8(p->a18);
    p->n30 = n;
    p->g34 = g_clock.t;
    switch (n) {
    case 1:
        { struct O *o = func_00205438(p->p10, 0x9D); struct VTE *e; o->n3C = 2; e = &o->vt[8]; e->pfn((char *)o + e->d); } p->n3C = 0;
        break;
    case 0:
        { struct O *o = func_00205438(p->p10, 0x9D); struct VTE *e; o->n3C = 9; e = &o->vt[8]; e->pfn((char *)o + e->d); }
        break;
    }
}
