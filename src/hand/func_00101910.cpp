#include "cref.h"
typedef int qword __attribute__((mode(TI)));
extern "C" CRef func_00201360(int c, void *aref, int *ak, ...);
extern "C" { void * PasegaApplyAseg__FP4ASEGP3ALOffi(void *p, int, float, float, int); CRef func_00101910(void *p, int c, void *aref); }
CRef func_00101910(void *p, int c, void *aref)
{
    int ak[4] = {0x2030, 0x1, 0x1, 0x100b};
    int v0;
    float v1;
    float v2;
    int v3;
    CRef ref = func_00201360(4, aref, ak, &v0, &v1, &v2, &v3);
    ref = PasegaApplyAseg__FP4ASEGP3ALOffi(p, v0, v1, v2, v3);
    return ref;
}
