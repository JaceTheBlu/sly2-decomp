#include "cref.h"
typedef int qword __attribute__((mode(TI)));
extern "C" CRef func_00201360(int c, void *aref, int *ak, ...);
extern "C" { void func_00207E08(void *p, void *, int, float, float, float, float); CRef func_00102F38(void *p, int c, void *aref); }
CRef func_00102F38(void *p, int c, void *aref)
{
    int ak[6] = {0x9010, 0x6, 0x1, 0x1, 0x1, 0x1};
    CRef v0;
    int v1;
    float v2;
    float v3;
    float v4;
    float v5;
    CRef ref = func_00201360(6, aref, ak, &v0, &v1, &v2, &v3, &v4, &v5);
    ref.Decref();
    ref.InitTag(0x24);
    func_00207E08(p, &v0, v1, v2, v3, v4, v5);
    return ref;
}
