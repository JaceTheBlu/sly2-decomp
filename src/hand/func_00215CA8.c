#include "util.h"
struct S { int x0; int x4; int x8; int xc; int x10; struct RGBA c1; struct RGBA c0; unsigned int x1c; };
void func_002160D8(struct S *p);
void func_00215CA8(struct S *p, int a)
{
    if (a)
        p->x0 = a;
    p->x4 = p->x0;
    p->x8 = p->xc;
    p->c1 = p->c0;
    p->x1c = 0x80000000;
    ((unsigned char *)&p->x1c)[3] = p->c1.bAlpha;
    func_002160D8(p);
}
