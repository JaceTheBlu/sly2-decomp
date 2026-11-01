#include "dl.h"
struct S { char pad[0x1D8]; void *powner; };
extern struct DL D_003E1A4C;
void OnLoRemove__FP2LO(struct S *p);
void func_001BD218(void *p);
void func_0011A2E8(struct DL *pdl, void *pv);
int func_0011A380(struct DL *pdl, void *pv);
void func_001BD1E0(void *p);
void func_001BC198(struct S *p)
{
    struct DL *pdl;
    OnLoRemove__FP2LO(p);
    if (p->powner) func_001BD218(p->powner);
    func_001BD1E0(p);
    pdl = &D_003E1A4C;
    if (func_0011A380(pdl, p)) func_0011A2E8(pdl, p);
}
