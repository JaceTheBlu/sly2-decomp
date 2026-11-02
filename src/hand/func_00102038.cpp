#include "cref.h"
typedef int qword __attribute__((mode(TI)));
extern "C" CRef func_00201360(int c, void *aref, int *ak, ...);
extern "C" { void *func_001FE5F0(void *p, int a, int b); CRef func_00102038(void *p, int c, void *aref); }
CRef func_00102038(void *p, int c, void *aref)
{
    int ak[2] = {0x10, 0x105D};
    int a, b;
    CRef ref = func_00201360(2, aref, ak, &a, &b);
    ref = func_001FE5F0(p, a, b);
    return ref;
}
