#include "vec.h"
#include "util.h"

void func_0011DD30(VECTOR *pvec, int a, RGBA *prgba)
{
    prgba->bRed = (int)(pvec->x * 255.0f + 0.5f);
    prgba->bGreen = (int)(pvec->y * 255.0f + 0.5f);
    prgba->bBlue = (int)(pvec->z * 255.0f + 0.5f);
    prgba->bAlpha = a;
}
