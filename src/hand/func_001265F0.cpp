#include "cref.h"
struct R;
struct Q { char pad[0x8]; int x8; R *pr; struct S *ps; };
struct R { char pad[0x10]; Q *pq; };
struct S { char pad[0xC]; R *pr; };
struct P { char pad[0xC]; R *pr; };
extern char D_002A43B0[];
extern "C" {
CRef func_00127838(Q *pq, CRef *aref);
void func_0021EC18(char *psz);
CRef func_001202D0(int n, int *p, CRef *aref);
CRef func_001265F0(P *p, CRef *aref);
}
CRef func_001265F0(P *p, CRef *aref)
{
    CRef ref;
    Q *pq = p->pr->pq;
    S *ps = pq->ps;
    ref = func_00127838(pq, aref);
    if (ref.m_tag == 0) {
        Q *pq2 = ps->pr->pq;
        func_0021EC18(D_002A43B0);
        func_001202D0(1, &pq2->x8, aref);
    }
    ref.Decref();
    ref.InitTag(0x24);
    return ref;
}
