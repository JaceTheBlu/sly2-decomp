#include "cref.h"
typedef int qword __attribute__((mode(TI)));
extern "C" CRef func_00201360(int c, void *aref, int *ak, ...);
extern "C" { void func_00181330(void *p, int, void *, void *); CRef func_0010FF18(void *p, int c, void *aref); }
CRef func_0010FF18(void *p, int c, void *aref)
{
    int ak[3] = {0x105f, 0xa, 0xa};
    union { qword q; } v1;
    union { qword q; } v2;
    int v0;
    CRef ref = func_00201360(3, aref, ak, &v0, &v1, &v2);
    ref.Decref();
    ref.InitTag(0x24);
    func_00181330(p, v0, &v1, &v2);
    return ref;
}
