#include "mat.h"
typedef int qword __attribute__((mode(TI)));
struct O19C0 { char pad[0xA0]; int xA0; };
struct O19CC { char pad[0x70]; qword x70; };
struct P {
    char pad[0x18C4]; void *x18C4;
    char pad1[0x1960 - 0x18C8]; qword x1960;
    char pad2[0x19C0 - 0x1970]; O19C0 *x19C0;
    char pad3[0x19CC - 0x19C4]; O19CC *x19CC;
    char pad4[0x1A00 - 0x19D0]; void *x1A00;
};
extern "C" {
qword func_001A62E8(void *p);
qword func_0022FCC8(int a, int b, qword v);
void func_0012D108(void *p, qword q);
qword func_0011F088(qword a, qword b, float g, float *p, int n);
void func_00190E18(P *p);
}
MATRIX3 BuildRotateVectorsMatrix__FUxUx(qword a, qword b);
MATRIX3 LoadRotateMatrixRad__FfUx(qword a, float g);
qword DecomposeRotateMatrixEuler__FP7MATRIX3(MATRIX3 *pm);
extern qword D_002A2DA0;
extern qword D_002A2DD0;
extern float D_002BF594;
extern float D_002BF598[];
extern float D_002DDED4;
static inline qword Sub(qword a, qword b)
{
    qword r;
    __asm__("vsub.xyzw %0, %1, %2" : "=j"(r) : "j"(a), "j"(b));
    return r;
}
static inline MATRIX3 Mul(const MATRIX3 &a, const MATRIX3 &b) return r
{
    __asm__("vmulax.xyz ACC, %1, %4x\n\tvmadday.xyz ACC, %2, %4y\n\tvmaddz.xyz %0, %3, %4z"
        : "=j"(r.r[0]) : "j"(a.r[0]), "j"(a.r[1]), "j"(a.r[2]), "j"(b.r[0]));
    __asm__("vmulax.xyz ACC, %1, %4x\n\tvmadday.xyz ACC, %2, %4y\n\tvmaddz.xyz %0, %3, %4z"
        : "=j"(r.r[1]) : "j"(a.r[0]), "j"(a.r[1]), "j"(a.r[2]), "j"(b.r[1]));
    __asm__("vmulax.xyz ACC, %1, %4x\n\tvmadday.xyz ACC, %2, %4y\n\tvmaddz.xyz %0, %3, %4z"
        : "=j"(r.r[2]) : "j"(a.r[0]), "j"(a.r[1]), "j"(a.r[2]), "j"(b.r[2]));
}
void func_00190E18(P *p)
{
    MATRIX3 m;
    qword d = Sub(func_001A62E8(p->x18C4), p->x19CC->x70);
    qword q = func_0022FCC8(0, p->x19C0->xA0, d);
    m = Mul(BuildRotateVectorsMatrix__FUxUx(D_002A2DA0, q), LoadRotateMatrixRad__FfUx(D_002A2DA0, D_002BF594));
    func_0012D108(p->x1A00, DecomposeRotateMatrixEuler__FP7MATRIX3(&m));
    p->x1960 = func_0011F088(p->x1960, D_002A2DD0, D_002DDED4, D_002BF598, 0);
}
