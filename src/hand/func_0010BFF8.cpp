#include "cref.h"
typedef int qword __attribute__((mode(TI)));
extern "C" CRef func_00201360(int c, void *aref, int *ak, ...);
extern "C" { void *func_00156B98(void *p, int a, qword q, int b); CRef func_0010BFF8(void *p, int c, void *aref); }
CRef func_0010BFF8(void *p, int c, void *aref)
{
    int ak[3] = {0x1046, 2, 0x2002};
    union { qword q; } u;
    int a, b;
    CRef ref = func_00201360(3, aref, ak, &a, &u, &b);
    ref = func_00156B98(p, a, u.q, b);
    return ref;
}
