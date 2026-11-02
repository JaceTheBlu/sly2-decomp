#include "cref.h"
typedef int TI __attribute__((mode(TI)));
typedef struct VR { TI vec; int cref; } VR;
extern char D_00452188[];
VR *func_0011CCC0(void *pslotheap);
CRef *func_00129248(CRef *pref, TI vec)
{
    VR *p;
    pref->m_tagk = 0x1A;
    p = func_0011CCC0(D_00452188);
    p->cref = 0;
    pref->m_p = p;
    p->cref++;
    ((VR *)pref->m_p)->vec = vec;
    return pref;
}
