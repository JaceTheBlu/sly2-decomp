#include "cref.h"
typedef int qword __attribute__((mode(TI)));
extern "C" CRef func_00201360(int c, void *aref, int *ak, void *an);
extern "C" {
void func_00170BA0(void *p, void *pv);
CRef func_00105E70(void *p, int c, void *aref);
}
CRef func_00105E70(void *p, int c, void *aref)
{
    union { qword q; } u;
    int k = 0xA;
    CRef ref = func_00201360(1, aref, &k, &u);
    ref.Decref();
    ref.InitTag(0x24);
    func_00170BA0(p, &u);
    return ref;
}
