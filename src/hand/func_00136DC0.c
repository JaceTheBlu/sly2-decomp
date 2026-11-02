#include "vtable.h"
struct A { char pad[0x30]; int x30; };
struct O { char pad[0xC]; struct VTE *pvt; char pad2[0x150 - 0x10]; struct A *pa; };
struct P { struct O *po; int x4; int x8; int xC; int x10; int x14; char pad[0xE0 - 0x18]; void *pE0; };
int func_00131968(void *p);
void func_00136F48(struct P *p, int k);
int func_001C4660(struct A *pa, float g, int n);
void func_001C4738(struct A *pa, int n);
void func_00136DC0(struct P *p, int k)
{
    if (p->pE0 && func_00131968(p->pE0))
        func_00136F48(p, -1);
    if (k != p->x4 && p->x4 != -1)
        func_00136F48(p, k);
    if (k != -1 && (p->x4 == -1 || p->xC)) {
        if (func_001C4660(p->po->pa, 0.1f, 0x80)) {
            struct O *po = p->po;
            if (((int (*)(void *, int))po->pvt[99].pfn)((char *)po + po->pvt[99].delta, 2)) {
                func_001C4738(p->po->pa, 0x80);
                func_00136F48(p, -1);
                func_00136F48(p, k);
            }
        }
    }
    if (!(p->po->pa->x30 & 0x80))
        p->x14 = 1;
}
