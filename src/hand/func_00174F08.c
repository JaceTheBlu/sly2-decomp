#include "vu0.h"
typedef int qword __attribute__((mode(TI)));
struct A { char pad[0x190]; qword q190; char pad2[0xFD0 - 0x1A0]; char aFD0[4]; };
struct S { char pad[0x10]; struct A *p10; char pad2[0x30 - 0x14]; int n30; int pad3; void *p38; int pad4; void *p40; };
extern qword D_002A2DD0;
void func_001EEFB8(struct S *p);
void func_00209618(void *a, struct A *b);
qword func_001A62E8(void *p);
float func_002458F0(float y, float x);
void func_00209818(void *p, float f);
void func_00174F08(struct S *p)
{
    func_001EEFB8(p);
    if (p->n30 == 0)
        func_00209618(p->p40, p->p10);
    else
        p->p10->q190 = D_002A2DD0;
    if (p->p38) {
        qword a = func_001A62E8(p->p38);
        qword b = func_001A62E8(p->p10);
        qword d;
        __asm__("vsub.xyzw %0, %1, %2" : "=j"(d) : "j"(a), "j"(b));
        func_00209818(p->p10->aFD0, func_002458F0(GetY(d), GetX(d)));
    }
}
