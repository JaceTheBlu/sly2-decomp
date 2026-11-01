#include "cref.h"
struct Q { char pad[0x10]; Q *pnext; };
struct R { char pad[0x10]; Q *pq; };
struct P { char pad[0xC]; R *pr; };
extern "C" {
CRef func_00127838(Q *pq, CRef *aref);
CRef func_00126758(P *p, CRef *aref);
}
CRef func_00126758(P *p, CRef *aref)
{
    CRef ref;
    Q *pqCond = p->pr->pq;
    Q *pqThen = pqCond->pnext;
    Q *pqElse = pqThen->pnext;
    ref = func_00127838(pqCond, aref);
    if (ref.m_tag == 1)
        ref = func_00127838(pqThen, aref);
    else if (pqElse)
        ref = func_00127838(pqElse, aref);
    else {
        ref.Decref();
        ref.InitTag(0x24);
    }
    return ref;
}
