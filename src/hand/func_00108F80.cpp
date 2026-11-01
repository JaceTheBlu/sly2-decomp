#include "cref.h"
typedef int qword __attribute__((mode(TI)));
extern "C" CRef func_00201360(int c, void *aref, int *ak, ...);
extern "C" { void func_001E1178(void *p, int, int, int, int, float, float, float); CRef func_00108F80(void *p, int c, void *aref); }
CRef func_00108F80(void *p, int c, void *aref)
{
    int ak[7] = {0xe, 0x6, 0x5, 0x5, 0x1, 0x1, 0x1};
    int v0;
    int v1;
    int v2;
    int v3;
    float v4;
    float v5;
    float v6;
    CRef ref = func_00201360(7, aref, ak, &v0, &v1, &v2, &v3, &v4, &v5, &v6);
    ref.Decref();
    ref.InitTag(0x24);
    func_001E1178(p, v0, v1, v2, v3, v4, v5, v6);
    return ref;
}
