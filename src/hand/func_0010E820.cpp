#include "cref.h"
typedef int qword __attribute__((mode(TI)));
extern "C" CRef func_00201360(int c, void *aref, int *ak, ...);
extern "C" { void func_001F8BF0(void *p, int, float, float, float, float, qword); CRef func_0010E820(void *p, int c, void *aref); }
CRef func_0010E820(void *p, int c, void *aref)
{
    int ak[6] = {0x5, 0x1, 0x1, 0x1, 0x1, 0x2};
    union { qword q; } v5;
    int v0;
    float v1;
    float v2;
    float v3;
    float v4;
    CRef ref = func_00201360(6, aref, ak, &v0, &v1, &v2, &v3, &v4, &v5);
    ref.Decref();
    ref.InitTag(0x24);
    func_001F8BF0(p, v0, v1, v2, v3, v4, v5.q);
    return ref;
}
