#include "vu0.h"
typedef int qword __attribute__((mode(TI)));
struct E { char pad[0x80]; qword v80; char pad2[0x20]; char subB0[0x10]; int nC0; };
struct P { char pad[0x58]; int n58; char pad2[0xE8 - 0x5C]; struct E *pe; char pad3[0x138 - 0xEC]; int n138; };
extern qword D_002A2DD0;
int func_0011D4D0(float, float, float);
qword func_001FA810(void *p, int n, qword v);
void func_001FAC30(struct P *p, qword v);
void func_00229798(struct P *p);
static inline int FNear(qword a, qword b)
{
    return func_0011D4D0(GetX(a), GetX(b), 0.0001f) && func_0011D4D0(GetY(a), GetY(b), 0.0001f) && func_0011D4D0(GetZ(a), GetZ(b), 0.0001f);
}
void func_001F9B20(struct P *p)
{
    int fUpd = 0;
    int fNear = FNear(D_002A2DD0, p->pe->v80);
    if (!fNear) fUpd = p->pe->nC0 != 3;
    if (fUpd) func_001FAC30(p, func_001FA810(p->pe->subB0, p->n58, p->pe->v80));
    if (p->n138) func_00229798(p);
}
