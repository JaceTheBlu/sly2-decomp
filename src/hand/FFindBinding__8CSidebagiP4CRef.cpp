#include "cref.h"
void func_00129658(CRef *pref, CRef *prefSrc) asm("func_00129658");
struct BINDING { int pad[2]; int sym; CRef ref; BINDING *pnext; };
class CSidebag {
public:
    int pad[2];
    BINDING *m_pbindingFirst;
    int FFindBinding(int sym, CRef *pref);
};
int CSidebag::FFindBinding(int sym, CRef *pref)
{
    for (BINDING *p = m_pbindingFirst; p; p = p->pnext) {
        if (p->sym == sym) {
            if (pref)
                func_00129658(pref, &p->ref);
            return 1;
        }
    }
    return 0;
}
