#include "cref.h"
typedef int qword __attribute__((mode(TI)));
extern "C" {
CRef func_00201360(int c, void *aref, int *ak, void *a0);
int func_00227C90(void *p, qword q);
CRef func_00104718(void *p, int c, void *aref);
}
CRef func_00104718(void *p, int c, void *aref)
{
    int ak[1] = {2};
    union { qword q; } u;
    CRef ref = func_00201360(1, aref, ak, &u);
    ref = func_00227C90(p, u.q) != 0;
    return ref;
}
