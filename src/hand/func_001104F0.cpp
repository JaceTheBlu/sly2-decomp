#include "cref.h"
typedef int qword __attribute__((mode(TI)));
extern "C" CRef func_00201360(int c, void *aref, int *ak, ...);
extern "C" { void func_001D4B48(void *p, int n, void *pu, float g); CRef func_001104F0(void *p, int c, void *aref); }
CRef func_001104F0(void *p, int c, void *aref)
{
    int ak[3] = {6, 1, 0xa};
    union { qword q; } u;
    int n;
    float g;
    CRef ref = func_00201360(3, aref, ak, &n, &g, &u);
    ref.Decref();
    ref.InitTag(0x24);
    func_001D4B48(p, n, &u, g);
    return ref;
}
