#include "cref.h"
typedef int qword __attribute__((mode(TI)));
extern "C" {
CRef func_00201360(int c, void *aref, int *ak, void *a0, void *a1);
void *func_001F8510(void *p, int a, int b);
CRef func_001014E8(void *p, int c, void *aref);
}
CRef func_001014E8(void *p, int c, void *aref)
{
    int ak[2] = {6, 0x104c};
    int a, b;
    CRef ref = func_00201360(2, aref, ak, &a, &b);
    ref = func_001F8510(p, a, b);
    return ref;
}
