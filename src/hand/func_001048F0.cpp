#include "cref.h"
typedef int qword __attribute__((mode(TI)));
extern "C" CRef func_00201360(int c, void *aref, int *ak, ...);
extern "C" { void * PsmaApplySm__FP2SMP3ALO3OIDii(void *p, int, int, int, int); CRef func_001048F0(void *p, int c, void *aref); }
CRef func_001048F0(void *p, int c, void *aref)
{
    int ak[4] = {0x2030, 0x6, 0x100b, 0x1054};
    int v0;
    int v1;
    int v2;
    int v3;
    CRef ref = func_00201360(4, aref, ak, &v0, &v1, &v2, &v3);
    ref = PsmaApplySm__FP2SMP3ALO3OIDii(p, v0, v1, v2, v3);
    return ref;
}
