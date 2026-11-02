#include "cref.h"
// pn reuses the aref parameter variable (if/else, tag != 0 arm first) -> beql s0=0
struct NODE { int cref; int x4; CRef ref; NODE *pnext; };
extern "C" CRef func_001238B0(void *pbasic, CRef *aref);
CRef func_001238B0(void *pbasic, CRef *aref)
{
    CRef ref(aref[0]);
    if (aref[1].m_tagk != 0) aref = (CRef *)aref[1].m_p; else aref = 0;
    NODE *pn = (NODE *)aref;
    for (; pn; pn = pn->pnext) {
        if (ref.m_tagk == 0x15) {
            if (pn->ref.m_tagk == 0x15) {
                CRef *p = &pn->ref;
                if (ref.m_tag > p->m_tag)
                    ref = *p;
            } else {
                CRef *p = &pn->ref;
                if ((float)ref.m_tag > p->m_g)
                    ref = *p;
            }
        } else {
            if (pn->ref.m_tagk == 0x15) {
                CRef *p = &pn->ref;
                if ((float)p->m_tag < ref.m_g)
                    ref = *p;
            } else {
                CRef *p = &pn->ref;
                if (ref.m_g > p->m_g)
                    ref = *p;
            }
        }
    }
    return ref;
}
