#include "cref.h"
typedef int qword __attribute__((mode(TI)));
extern "C" CRef func_00201360(int c, void *aref, int *ak, ...);
extern "C" { void func_00163838(void *p, int, void *, int, int); CRef func_0010F030(void *p, int c, void *aref); }
CRef func_0010F030(void *p, int c, void *aref)
{
    int ak[4] = {0x6, 0x9050, 0x6, 0xf};
    CRef v1;
    int v0;
    int v2;
    int v3;
    CRef ref = func_00201360(4, aref, ak, &v0, &v1, &v2, &v3);
    ref.Decref();
    ref.InitTag(0x24);
    func_00163838(p, v0, &v1, v2, v3);
    return ref;
}
