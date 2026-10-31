#include "util.h"

void func_0011DCD8(RGBA *prgba, float *pg)
{
    pg[0] = prgba->bRed * (1.0f / 255.0f);
    pg[1] = prgba->bGreen * (1.0f / 255.0f);
    pg[2] = prgba->bBlue * (1.0f / 255.0f);
}
