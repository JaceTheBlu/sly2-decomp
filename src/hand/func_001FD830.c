#include "clock.h"
struct X;
struct Q { char pad[0x38]; struct Q *pNext; };
struct K { int a, b, c; };
struct P { char pad[0x4C]; struct Q *pq; char pad1[0x58 - 0x50]; int n58; char pad2[0x15C - 0x5C]; float f15C; char pad3[0x1F0 - 0x160];
    long l1F0; long l1F8; struct X *r200; int c; struct X *a[8]; struct X *r228; };
extern struct CLOCK g_clock;
extern int D_002BD4C0;
extern struct K D_002A8288;
long TickNow__FP5CLOCK(struct CLOCK *);
void func_001FDA48(struct P *);
void func_001FDBA8(struct P *);
void func_001FB060(struct X *);
void func_001FB018(struct X *);
void func_001FDC08(struct P *);
void func_001FDEC0(struct P *);
void func_001FDEC8(struct P *);
int func_001FE5E0(struct P *);
float GSmooth__FfffP3SMPPf(float, float, float, struct K *, int);
void func_001FEA60(struct P *, int, float, int);
void func_001FB8E0(struct Q *);
int func_00231C48(void);
void func_001FD830(struct P *p)
{
    struct X *top;
    float f, g;
    struct K k;
    struct Q *q;
    p->l1F8 = p->l1F0;
    p->l1F0 = TickNow__FP5CLOCK(&g_clock);
    func_001FDA48(p);
    func_001FDBA8(p);
    top = p->c > 0 ? *(p->a + p->c - 1) : 0;
    if (D_002BD4C0 == 3) {
        if (p->n58) {
            if (top) func_001FB060(top);
            if (p->r228) func_001FB060(p->r228);
            if (p->r200) func_001FB060(p->r200);
            p->n58 = 0;
        }
    } else if (!p->n58) {
        if (top) func_001FB018(top);
        if (p->r228) func_001FB018(p->r228);
        if (p->r200) func_001FB018(p->r200);
        p->n58 = 1;
    }
    g = 1.0f;
    func_001FDC08(p);
    func_001FDEC0(p);
    func_001FDEC8(p);
    k = D_002A8288;
    if (func_001FE5E0(p) && g_clock.dt == 0.0f) g = 0.0f;
    f = GSmooth__FfffP3SMPPf(p->f15C, g, g_clock.dtFrame, &k, 0);
    func_001FEA60(p, 0, f, 2);
    func_001FEA60(p, 1, f, 2);
    func_001FEA60(p, 2, g, 2);
    for (q = p->pq; q;) {
        struct Q *n = q->pNext;
        func_001FB8E0(q);
        q = n;
    }
    func_00231C48();
}
