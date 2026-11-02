#include "cref.h"
typedef int qword __attribute__((mode(TI)));
extern "C" CRef func_00201360(int c, void *aref, int *ak, ...);
extern "C" { void func_0020AFF0(void *p, int, float, float, float, float); CRef func_00104558(void *p, int c, void *aref); }
CRef func_00104558(void *p, int c, void *aref)
{
    int ak[5] = {0x6, 0x1, 0x1, 0x1, 0x1};
    int v0;
    float v1;
    float v2;
    float v3;
    float v4;
    CRef ref = func_00201360(5, aref, ak, &v0, &v1, &v2, &v3, &v4);
    ref.Decref();
    ref.InitTag(0x24);
    func_0020AFF0(p, v0, v1, v2, v3, v4);
    return ref;
}
