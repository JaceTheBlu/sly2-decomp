#include "cref.h"
typedef int qword __attribute__((mode(TI)));
extern "C" CRef func_00201360(int c, void *aref, int *ak, ...);
extern "C" { void func_00132CC8(void *p, int n, void *pu); CRef func_001004A0(void *p, int c, void *aref); }
CRef func_001004A0(void *p, int c, void *aref)
{
    int ak[2] = {0x15, 9};
    union { qword q; } u;
    int n;
    CRef ref = func_00201360(2, aref, ak, &n, &u);
    ref.Decref();
    ref.InitTag(0x24);
    func_00132CC8(p, n, &u);
    return ref;
}
