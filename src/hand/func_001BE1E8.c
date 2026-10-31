#include "dl.h"
extern struct DL D_003E1A4C;
void func_0011A2E8(struct DL *pdl, void *pv);
void func_001BD040(void *pv);
int FIsDlEmpty__FP2DL(struct DL *pdl);
void func_001BE1E8(void)
{
    while (!FIsDlEmpty__FP2DL(&D_003E1A4C)) {
        void *pv = D_003E1A4C.head;
        func_0011A2E8(&D_003E1A4C, pv);
        func_001BD040(pv);
    }
}
