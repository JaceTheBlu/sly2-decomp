#include "cref.h"
typedef int qword __attribute__((mode(TI)));
extern "C" CRef func_00201360(int c, void *aref, int *ak, ...);
extern "C" { void func_00207CF8(void *p, void *, int, int, int, int); CRef func_00102D30(void *p, int c, void *aref); }
CRef func_00102D30(void *p, int c, void *aref)
{
    int ak[5] = {0x9010, 0x6, 0x6, 0x6, 0x6};
    CRef v0;
    int v1;
    int v2;
    int v3;
    int v4;
    CRef ref = func_00201360(5, aref, ak, &v0, &v1, &v2, &v3, &v4);
    ref.Decref();
    ref.InitTag(0x24);
    func_00207CF8(p, &v0, v1, v2, v3, v4);
    return ref;
}
