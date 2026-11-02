#include "cref.h"
typedef int qword __attribute__((mode(TI)));
extern "C" CRef func_00201360(int c, void *aref, int *ak, ...);
extern "C" { void func_00212828(void *p, CRef *pref); CRef func_0010DE58(void *p, int c, void *aref); }
CRef func_0010DE58(void *p, int c, void *aref)
{
    int k = 0x8010;
    CRef r;
    CRef ref = func_00201360(1, aref, &k, &r);
    ref.Decref();
    ref.InitTag(0x24);
    func_00212828(p, &r);
    return ref;
}
