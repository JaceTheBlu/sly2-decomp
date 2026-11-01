#include "cref.h"
typedef int qword __attribute__((mode(TI)));
extern "C" CRef func_00201360(int c, void *aref, int *ak, ...);
extern "C" { void func_001E0310(void *p, CRef *pref); CRef func_00106C08(void *p, int c, void *aref); }
CRef func_00106C08(void *p, int c, void *aref)
{
    int k = 0x8006;
    CRef r;
    CRef ref = func_00201360(1, aref, &k, &r);
    ref.Decref();
    ref.InitTag(0x24);
    func_001E0310(p, &r);
    return ref;
}
