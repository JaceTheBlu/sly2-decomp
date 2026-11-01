#include "cref.h"
typedef int qword __attribute__((mode(TI)));
extern "C" CRef func_00201360(int c, void *aref, int *ak, ...);
extern "C" { void func_00143090(void *p, void *, void *, void *); CRef func_0010AE28(void *p, int c, void *aref); }
CRef func_0010AE28(void *p, int c, void *aref)
{
    int ak[3] = {0xa, 0xa, 0xa};
    union { qword q; } v0;
    union { qword q; } v1;
    union { qword q; } v2;
    CRef ref = func_00201360(3, aref, ak, &v0, &v1, &v2);
    ref.Decref();
    ref.InitTag(0x24);
    func_00143090(p, &v0, &v1, &v2);
    return ref;
}
