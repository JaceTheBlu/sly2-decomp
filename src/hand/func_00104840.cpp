#include "cref.h"
typedef int qword __attribute__((mode(TI)));
extern "C" CRef func_00201360(int c, void *aref, int *ak, ...);
extern "C" { void *func_001F0380(void *p, int a, int b, int c); CRef func_00104840(void *p, int c, void *aref); }
CRef func_00104840(void *p, int c, void *aref)
{
    int ak[3] = {0x2030, 6, 0x100B};
    int a, b, d;
    CRef ref = func_00201360(3, aref, ak, &a, &b, &d);
    ref = func_001F0380(p, a, b, d);
    return ref;
}
