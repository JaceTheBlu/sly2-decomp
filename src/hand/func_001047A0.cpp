#include "cref.h"
typedef int qword __attribute__((mode(TI)));
extern "C" {
CRef func_00201360(int c, void *aref, int *ak, void *a0, void *a1);
int func_00227D20(void *p, qword q, float g);
CRef func_001047A0(void *p, int c, void *aref);
}
CRef func_001047A0(void *p, int c, void *aref)
{
    int ak[2] = {2, 0x16};
    union { qword q; } u;
    float g;
    CRef ref = func_00201360(2, aref, ak, &u, &g);
    ref = func_00227D20(p, u.q, g) != 0;
    return ref;
}
