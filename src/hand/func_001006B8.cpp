#include "cref.h"
typedef int qword __attribute__((mode(TI)));
extern "C" CRef func_00201360(int c, void *aref, int *ak, ...);
extern "C" { void func_00132DE0(void *p, int n, qword q); CRef func_001006B8(void *p, int c, void *aref); }
CRef func_001006B8(void *p, int c, void *aref)
{
    int ak[2] = {0x15, 2};
    union { qword q; } u;
    int n;
    CRef ref = func_00201360(2, aref, ak, &n, &u);
    ref.Decref();
    ref.InitTag(0x24);
    func_00132DE0(p, n, u.q);
    return ref;
}
