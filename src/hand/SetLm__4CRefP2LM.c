#include "cref.h"
typedef struct CLQ { int a, b; } CLQ;
typedef struct LR { CLQ v; int cref; } LR;
extern char D_004521D0[];
LR *func_0011CCC0(void *pslotheap);
void Decref__4CRef(CRef *pref);
CRef *SetLm__4CRefP2LM(CRef *pref, CLQ *pv)
{
    LR *p;
    Decref__4CRef(pref);
    pref->m_tagk = 0x1D;
    p = func_0011CCC0(D_004521D0);
    p->cref = 0;
    pref->m_p = p;
    p->cref++;
    ((LR *)pref->m_p)->v = *pv;
    return pref;
}
