#include "cref.h"
typedef int qword __attribute__((mode(TI)));
extern "C" CRef func_00201360(int c, void *aref, int *ak, ...);
extern "C" { void * func_00156698(void *p, qword, int); CRef func_0010D840(void *p, int c, void *aref); }
CRef func_0010D840(void *p, int c, void *aref)
{
    int ak[2] = {0x2, 0x2002};
    union { qword q; } v0;
    int v1;
    CRef ref = func_00201360(2, aref, ak, &v0, &v1);
    ref = func_00156698(p, v0.q, v1);
    return ref;
}
