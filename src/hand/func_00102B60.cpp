#include "cref.h"
typedef int qword __attribute__((mode(TI)));
extern "C" CRef func_00201360(int c, void *aref, int *ak, ...);
extern "C" { void func_00207BC8(void *p, void *, int, int); CRef func_00102B60(void *p, int c, void *aref); }
CRef func_00102B60(void *p, int c, void *aref)
{
    int ak[3] = {0x9010, 0x6, 0x100b};
    CRef v0;
    int v1;
    int v2;
    CRef ref = func_00201360(3, aref, ak, &v0, &v1, &v2);
    ref.Decref();
    ref.InitTag(0x24);
    func_00207BC8(p, &v0, v1, v2);
    return ref;
}
