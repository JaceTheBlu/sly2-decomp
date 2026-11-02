#include "vu0.h"
typedef int qword __attribute__((mode(TI)));
int func_0011D4D0(float a, float b, float eps);
extern qword D_002A2DD0;
static __inline__ int FVecsNear(qword a, qword b)
{
    return func_0011D4D0(GetX(a), GetX(b), 1e-4f) && func_0011D4D0(GetY(a), GetY(b), 1e-4f) &&
           func_0011D4D0(GetZ(a), GetZ(b), 1e-4f);
}
typedef struct KEY { float g; float dg; } KEY;
typedef struct T { int pad; int c; float *at; KEY *ak[3]; int pad2[2]; float v[4]; } T;
typedef union VQ { float af[4]; qword q; } VQ;
typedef struct OBJ {
    char pad[0x80];
    float t0;
    float t1;
    float *pt0;
    float *pt1;
    char pad90[0x9A - 0x90];
    short s9A;
    char pad9C[0xC0 - 0x9C];
    VQ pos0;
    VQ dpos0;
    VQ pos1;
    VQ dpos1;
} OBJ;
int func_0012C708(T *t, float g);
void func_0012C768(T *t, OBJ *po)
{
    int i;
    unsigned int j;
    int f;
    if (t->c) {
        i = func_0012C708(t, *po->pt0);
        po->t0 = t->at[i - 1];
        po->t1 = t->at[i];
    } else {
        po->pt0 = &po->t0;
        po->t1 = 1.0f;
        po->pt1 = &po->t1;
        po->t0 = 0;
    }
    for (j = 0; j < 3; j++) {
        KEY *ak = t->ak[j];
        if (ak) {
            KEY *k0 = &ak[i - 1];
            KEY *k1 = &ak[i];
            po->pos0.af[j] = k0->g;
            po->dpos0.af[j] = k0->dg;
            po->pos1.af[j] = k1->g;
            po->dpos1.af[j] = k1->dg;
        } else {
            po->pos0.af[j] = t->v[j];
            po->dpos0.af[j] = 0;
            po->pos1.af[j] = t->v[j];
            po->dpos1.af[j] = 0;
        }
    }
    f = FVecsNear(po->pos0.q, po->pos1.q) && FVecsNear(D_002A2DD0, po->dpos0.q) &&
        FVecsNear(D_002A2DD0, po->dpos1.q);
    po->s9A = f ? 2 : 1;
}
