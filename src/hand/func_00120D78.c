#include "cref.h"
typedef struct PAIR { int a; int b; CRef ref; struct PAIR *pnext; } PAIR;
void SetTag__4CRef4TAGK(CRef *pref, int tagk);
void func_00129658(CRef *pref, CRef *prefSrc);
CRef *func_001291A8(CRef *pref, CRef *prefSrc);
void func_00129EC8(CRef *pref);
CRef *func_00120D78(CRef *ret, void *pbasic, CRef *aref)
{
    CRef ref;
    SetTag__4CRef4TAGK(&ref, 0);
    if (aref[0].m_tagk == 0x1F) {
        PAIR *p = (PAIR *)aref[0].m_tag;
        CRef *pn = &aref[1];
        int i;
        for (i = 0; p; p = p->pnext, i++) {
            if (i == pn->m_tag) {
                func_00129658(&ref, &p->ref);
                break;
            }
        }
    }
    func_001291A8(ret, &ref);
    func_00129EC8(&ref);
    return ret;
}
