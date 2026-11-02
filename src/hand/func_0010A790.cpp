#include "cref.h"
typedef int qword __attribute__((mode(TI)));
extern "C" CRef func_00201360(int c, void *aref, int *ak, ...);
extern "C" { void func_00141968(void *p, qword, float, float); CRef func_0010A790(void *p, int c, void *aref); }
CRef func_0010A790(void *p, int c, void *aref)
{
    int ak[3] = {0x2, 0x1, 0x1};
    union { qword q; } v0;
    float v1;
    float v2;
    CRef ref = func_00201360(3, aref, ak, &v0, &v1, &v2);
    ref.Decref();
    ref.InitTag(0x24);
    func_00141968(p, v0.q, v1, v2);
    return ref;
}
