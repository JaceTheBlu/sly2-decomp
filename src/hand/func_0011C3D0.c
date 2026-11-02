typedef struct MATRIX4 { float mat[4][4]; } __attribute__((aligned(16))) MATRIX4;

MATRIX4 func_0011C318(void *pv);
MATRIX4 __ml__FRC7MATRIX4T0(MATRIX4 *pmatA, MATRIX4 *pmatB);

void func_0011C3D0(void *pv, MATRIX4 *pmat, MATRIX4 *pmatOut)
{
    MATRIX4 matRes;
    MATRIX4 matT;
    matT = func_0011C318(pv);
    matRes = __ml__FRC7MATRIX4T0(pmat, &matT);
    *pmatOut = matRes;
}
