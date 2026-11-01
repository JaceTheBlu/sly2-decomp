#include "vu0.h"
struct MATRIX3 { float mat[3][4]; } __attribute__((aligned(16)));
extern "C" float atan2f(float y, float x);

void DecomposeRotateMatrixPanTilt(MATRIX3 *pmat, float *ppan, float *ptilt)
{
    *ppan = atan2f(pmat->mat[0][1], pmat->mat[0][0]);
    *ptilt = atan2f(pmat->mat[0][2], GSqrt(pmat->mat[0][0] * pmat->mat[0][0] + pmat->mat[0][1] * pmat->mat[0][1]));
}
