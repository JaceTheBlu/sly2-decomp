#include "cref.h"
typedef int qword __attribute__((mode(TI)));
extern "C" CRef func_00201360(int c, void *aref, int *ak, void *an);
struct VT { short d; short pad; void *pfn; };
struct LO { char pad[0xC]; VT *pvt; };
extern "C" CRef func_00100C80(LO *p, int c, void *aref);
CRef func_00100C80(LO *p, int c, void *aref)
{
    union { qword q; } u;
    int k = 2;
    CRef ref = func_00201360(1, aref, &k, &u);
    VT *pvt = &p->pvt[73];
    ref = ((int (*)(void *, qword))pvt->pfn)((char *)p + pvt->d, u.q) != 0;
    return ref;
}
