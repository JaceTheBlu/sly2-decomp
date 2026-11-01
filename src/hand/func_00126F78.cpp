#include "cref.h"
struct Q { char pad[0x10]; Q *pnext; };
struct R { char pad[0x10]; Q *pq; };
struct P { char pad[0xC]; R *pr; };
extern "C" {
CRef func_00127838(Q *pq, CRef *aref);
CRef func_00126F78(P *p, CRef *aref);
}
CRef func_00126F78(P *p, CRef *aref)
{
    CRef ref;
    Q *pqCond = p->pr->pq;
    Q *pqBody = pqCond->pnext;
    for (;;) {
        ref = func_00127838(pqCond, aref);
        if (ref.m_tagk == 0x17 && ref.m_tag == 0)
            break;
        ref = func_00127838(pqBody, aref);
    }
    ref.Decref();
    ref.InitTag(0x24);
    return ref;
}
