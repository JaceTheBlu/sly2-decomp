#include "cref.h"
typedef struct CLT { int a, b, c; } CLT;
typedef struct TR { CLT v; int cref; } TR;
extern char D_004521E8[];
TR *func_0011CCC0(void *pslotheap);
void Decref__4CRef(CRef *pref);
CRef *__4CRefPC3V12(CRef *pref, CLT *pv)
{
    TR *p;

    pref->m_tagk = 0x1E;
    p = func_0011CCC0(D_004521E8);
    p->cref = 0;
    pref->m_p = p;
    p->cref++;
    ((TR *)pref->m_p)->v = *pv;
    return pref;
}
