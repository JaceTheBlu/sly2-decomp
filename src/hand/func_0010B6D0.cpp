#include "cref.h"
typedef int qword __attribute__((mode(TI)));
extern "C" CRef func_00201360(int c, void *aref, int *ak, void *an);
extern "C" {
void func_0018DF58(void *p, qword q);
CRef func_0010B6D0(void *p, int c, void *aref);
}
CRef func_0010B6D0(void *p, int c, void *aref)
{
    union { qword q; } u;
    int k = 2;
    CRef ref = func_00201360(1, aref, &k, &u);
    ref.Decref();
    ref.InitTag(0x24);
    func_0018DF58(p, u.q);
    return ref;
}
