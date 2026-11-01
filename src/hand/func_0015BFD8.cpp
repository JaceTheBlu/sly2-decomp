#include "mat.h"
#include "vu0.h"
#include "clock.h"
typedef int qword __attribute__((mode(TI)));
struct VU_FLOAT { qword q; VU_FLOAT(float f) { __asm__("" : "=r"(q) : "0"(*(int *)&f)); } };
extern CLOCK g_clock;
extern MATRIX4 D_002A2D30;
struct X { float x, y, z, w; qword axis; float gRot; float gScale; };
void LoadRotateMatrixRad__FfUx(MATRIX3 *pm, float g, qword axis);
MATRIX4 operator*(const MATRIX4 &a, const MATRIX4 &b);
MATRIX4 operator*(const MATRIX4 &m, VU_FLOAT s);
static inline MATRIX4 operator+(const MATRIX4 &a, const MATRIX4 &b) return r
{
    for (int i = 0; i < 4; i++)
        r.r[i] = QwAdd(a.r[i], b.r[i]);
}
extern "C" MATRIX4 func_0015BFD8(X *p);
MATRIX4 func_0015BFD8(X *p)
{
    MATRIX4 mScale = D_002A2D30;
    float *pf = (float *)&mScale;
    pf[0] = p->gScale;
    pf[5] = p->gScale;
    pf[10] = p->gScale;
    pf[12] = p->x;
    pf[13] = p->y;
    pf[14] = p->z;
    MATRIX4 mRot = D_002A2D30;
    MATRIX4 *pmRot = &mRot;
    if (p->gRot != 0.0f) {
        MATRIX3 m3;
        LoadRotateMatrixRad__FfUx(&m3, p->gRot * g_clock.dt, p->axis);
        *(MATRIX3 *)pmRot = m3;
    }
    MATRIX4 mD;
    mD = *pmRot * mScale * VU_FLOAT(g_clock.dt);
    return *pmRot + mD;
}
