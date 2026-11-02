#include "cref.h"
typedef int qword __attribute__((mode(TI)));
extern "C" {
CRef func_00201360(int c, void *aref, int *ak, void *an);
void *func_001C4AF8(void *p, qword q);
CRef func_0010BF70(void *p, int c, void *aref);
}
CRef func_0010BF70(void *p, int c, void *aref)
{
    union { qword q; } u;
    int k = 2;
    CRef ref = func_00201360(1, aref, &k, &u);
    ref = func_001C4AF8(p, u.q);
    return ref;
}
