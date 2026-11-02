#include "vu0.h"
typedef int qword __attribute__((mode(TI)));
struct A { int cb; int align; };
struct E8 { struct V *pv; int x4; };
struct V { qword pos; int c; struct E8 *ae; int pad[2]; };
struct VS { qword pos; int c; int ai[3]; };
struct F { struct V *apv[3]; };
struct FS { int ai[3]; };
struct P { float x, y; int z; unsigned short c, d; };
struct S { char pad[0xE0]; int cE0; struct V *aE4; int cE8; struct F *aEC; int cF0; struct P *aF4; char p1[0x114 - 0xF8]; int x114; };
struct G { char pad[0x3D70]; int x3D70; };
extern struct G g_sw;
extern struct VS D_002C0C10[];
extern struct FS D_002C0C90[];
void *PvAllocSwClearImpl__FP7SWALLOC(struct A *pa);
void *PvAllocSwImpl__Fi(struct A *pa);
void func_001C0880(int *p);
void func_001C0648(struct S *p)
{
    struct A a;
    int i, j, k;
    struct P *pp;
    float g;
    p->cE0 = 4;
    a.cb = 0x80;
    a.align = 0x10;
    p->aE4 = PvAllocSwClearImpl__FP7SWALLOC(&a);
    for (i = 0; i < p->cE0; i++) {
        struct VS *ps = &D_002C0C10[i];
        struct V *pd = &p->aE4[i];
        pd->pos = ps->pos;
        pd->c = ps->c;
        a.cb = pd->c * 8 + 8;
        a.align = 0x10;
        pd->ae = PvAllocSwImpl__Fi(&a);
        for (j = 0; j < pd->c; j++)
            { struct E8 *pe = &pd->ae[j]; pe->pv = &p->aE4[ps->ai[j]]; }
    }
    p->cE8 = 2;
    a.cb = 0x18;
    a.align = 0x10;
    p->aEC = PvAllocSwClearImpl__FP7SWALLOC(&a);
    for (k = 0; k < p->cE8; k++) {
        struct V **ppv = p->aEC[k].apv;
        int *pi = D_002C0C90[k].ai;
        for (i = 0; i < 3; i++)
            *ppv++ = &p->aE4[*pi++];
    }
    p->cF0 = 1;
    a.cb = 0x10;
    a.align = 0x10;
    pp = PvAllocSwClearImpl__FP7SWALLOC(&a);
    p->aF4 = pp;
    g = GSqrt(2.0f) * 0.5f;
    pp->c = 0xC001;
    pp->d = 0xC000;
    pp->z = 0;
    pp->x = g;
    pp->y = -g;
    func_001C0880(&p->cE0);
    p->x114 = ++g_sw.x3D70;
}
