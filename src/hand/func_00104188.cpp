#include "cref.h"
typedef int qword __attribute__((mode(TI)));
extern "C" CRef func_00201360(int c, void *aref, int *ak, ...);
extern "C" { int func_001541D8(void *p, int, int); CRef func_00104188(void *p, int c, void *aref); }
CRef func_00104188(void *p, int c, void *aref)
{
    int ak[2] = {0x2002, 0x106b};
    int v0;
    int v1;
    CRef ref = func_00201360(2, aref, ak, &v0, &v1);
    ref = func_001541D8(p, v0, v1);
    return ref;
}
