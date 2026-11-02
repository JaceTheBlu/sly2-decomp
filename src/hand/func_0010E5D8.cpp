#include "cref.h"
typedef int qword __attribute__((mode(TI)));
extern "C" CRef func_00201360(int c, void *aref, int *ak, ...);
extern "C" { void func_001F8A78(void *p, int, int, qword); CRef func_0010E5D8(void *p, int c, void *aref); }
CRef func_0010E5D8(void *p, int c, void *aref)
{
    int ak[3] = {0x100d, 0x5, 0x2};
    union { qword q; } v2;
    int v0;
    int v1;
    CRef ref = func_00201360(3, aref, ak, &v0, &v1, &v2);
    ref.Decref();
    ref.InitTag(0x24);
    func_001F8A78(p, v0, v1, v2.q);
    return ref;
}
