#include "cref.h"
typedef int qword __attribute__((mode(TI)));
extern "C" CRef func_00201360(int c, void *aref, int *ak, ...);
extern "C" { void func_0019EAA0(void *p, qword a, qword b); CRef func_0010B340(void *p, int c, void *aref); }
CRef func_0010B340(void *p, int c, void *aref)
{
    int ak[2] = {2, 2};
    union { qword q; } u;
    union { qword q; } v;
    CRef ref = func_00201360(2, aref, ak, &u, &v);
    ref.Decref();
    ref.InitTag(0x24);
    func_0019EAA0((char *)p + 0xF50, u.q, v.q);
    return ref;
}
