#include "cref.h"
typedef int qword __attribute__((mode(TI)));
extern "C" CRef func_00201360(int c, void *aref, int *ak, ...);
extern "C" { void func_00142310(void *p, float, float, void *, float, float, qword, qword); CRef func_0010B230(void *p, int c, void *aref); }
CRef func_0010B230(void *p, int c, void *aref)
{
    int ak[7] = {0x1, 0x1, 0xa, 0x1, 0x1, 0x2, 0x2};
    union { qword q; } v2;
    union { qword q; } v5;
    union { qword q; } v6;
    float v0;
    float v1;
    float v3;
    float v4;
    CRef ref = func_00201360(7, aref, ak, &v0, &v1, &v2, &v3, &v4, &v5, &v6);
    ref.Decref();
    ref.InitTag(0x24);
    func_00142310(p, v0, v1, &v2, v3, v4, v5.q, v6.q);
    return ref;
}
