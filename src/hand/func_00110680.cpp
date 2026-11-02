#include "cref.h"
typedef int qword __attribute__((mode(TI)));
extern "C" CRef func_00201360(int c, void *aref, int *ak, ...);
extern "C" { void func_001D4C48(void *p, int n, void *pu); CRef func_00110680(void *p, int c, void *aref); }
CRef func_00110680(void *p, int c, void *aref)
{
    int ak[2] = {6, 0xa};
    union { qword q; } u;
    int n;
    CRef ref = func_00201360(2, aref, ak, &n, &u);
    ref.Decref();
    ref.InitTag(0x24);
    func_001D4C48(p, n, &u);
    return ref;
}
