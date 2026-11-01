#include "cref.h"
typedef int qword __attribute__((mode(TI)));
extern "C" CRef func_00201360(int c, void *aref, int *ak, ...);
extern "C" { void func_0015C198(void *p, int, int, qword, qword, float, float); CRef func_00105BE0(void *p, int c, void *aref); }
CRef func_00105BE0(void *p, int c, void *aref)
{
    int ak[6] = {0x1026, 0x2002, 0x2, 0x2, 0x1, 0x1};
    union { qword q; } v2;
    union { qword q; } v3;
    int v0;
    int v1;
    float v4;
    float v5;
    CRef ref = func_00201360(6, aref, ak, &v0, &v1, &v2, &v3, &v4, &v5);
    ref.Decref();
    ref.InitTag(0x24);
    func_0015C198(p, v0, v1, v2.q, v3.q, v4, v5);
    return ref;
}
