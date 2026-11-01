#include "vtable.h"
typedef int qword __attribute__((mode(TI)));
struct LO { int pad[3]; struct VTE *pvt; };
struct M4 { qword r[3]; qword pos; };
struct P { int pad[4]; struct LO *apo[4]; qword apos[2]; void *ap40[2]; int a48; };
extern char D_002C44F0[];
float func_001E6610(int);
float func_001E6630(int);
void func_001E67B8(int, qword *, int, float);
void func_001E93F0(struct P *p, int i, struct LO *po)
{
    p->apo[i] = po;
    if (po) {
        struct M4 m;
        struct VTE *pe = &po->pvt[32];
        p->ap40[i] = ((void *(*)(void *, struct M4 *))pe->pfn)((char *)po + pe->delta, &m);
        *(p->apos + i) = m.pos;
    } else {
        float f;
        p->ap40[i] = D_002C44F0;
        if (i == 0)
            f = func_001E6610(p->a48);
        else
            f = func_001E6630(p->a48);
        func_001E67B8(p->a48, &p->apos[i], 0, f);
    }
}
