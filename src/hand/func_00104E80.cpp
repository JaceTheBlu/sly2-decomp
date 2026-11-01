#include "cref.h"
typedef int qword __attribute__((mode(TI)));
extern "C" CRef func_00201360(int c, void *aref, int *ak, ...);
struct VTE { short d; short pad; void (*pfn)(void *, int, void *); };
struct LO { char pad[0xC]; VTE *pvt; };
extern "C" { CRef func_00104E80(LO *p, int c, void *aref); }
CRef func_00104E80(LO *p, int c, void *aref)
{
    int ak[2] = {0x2030, 2};
    union { qword q; } u;
    int n;
    CRef ref = func_00201360(2, aref, ak, &n, &u);
    ref.Decref();
    ref.InitTag(0x24);
    VTE *pvte = &p->pvt[78];
    pvte->pfn((char *)p + pvte->d, n, &u);
    return ref;
}
