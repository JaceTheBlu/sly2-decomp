#include "vtable.h"
#include "mat.h"
typedef int qword __attribute__((mode(TI)));
typedef struct LO LO;
struct LO {
    char pad[0xC];
    VTE *vt;
    char pad2[0x18];
    int x28;
    signed char ips;
    char x2D;
    long k : 4;
    unsigned long b : 8;
    unsigned int f : 1;
    char pad3[0x20];
    LO *x50;
    char pad4[0xC];
    MATRIX4 m60;
    LO *xA0;
};
MATRIX4 __ml__FRC7MATRIX4T0(void *, MATRIX4 *);
void func_001A5900(LO *, LO *, LO *, int);

void func_002315F0(LO *p, LO *pNew, LO *pParent, int grf)
{
    MATRIX4 m;
    if (grf & 3) {
        if (p->f) {
            m = *((MATRIX4 * (*)(void *))p->vt[31].pfn)((char *)p + p->vt[31].delta);
        } else {
            LO *q;
            m = p->m60;
            for (q = p->x50; q; q = q->xA0)
            {
                MATRIX4 t = __ml__FRC7MATRIX4T0(q, &m);
                m = t;
            }
        }
    }
    if (pParent)
        p->x50 = pParent;
    else if (pNew)
        p->x50 = *(LO **)((char *)pNew + 0x60);
    else
        p->x50 = 0;
    func_001A5900(p, pNew, pParent, grf);
    if (grf & 1)
        ((void (*)(void *, qword))p->vt[29].pfn)((char *)p + p->vt[29].delta, m.r[3]);
    if (grf & 2)
        ((void (*)(void *, MATRIX4 *))p->vt[30].pfn)((char *)p + p->vt[30].delta, &m);
}
