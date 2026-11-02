#define CREF_PLAIN   /* this source uses CRef as plain data: no constructor/destructor calls */
#include "cref.h"
struct BINDING { int a, b; unsigned int sym; CRef ref; BINDING *pnext; };
class CFrame {
public:
    int a, b;
    int cframe;
    CFrame *apframe[4];
    BINDING *pbindingFirst;
    int fBusy;
    CRef *PrefFindBinding(unsigned int sym, int fRecurse);
    CRef *PrefFindLocal(unsigned int sym) { BINDING *pb; for (pb = pbindingFirst; pb; pb = pb->pnext) if (pb->sym == sym) return &pb->ref; return 0; }
};
CRef *CFrame::PrefFindBinding(unsigned int sym, int fRecurse)
{
    CRef *pref = 0;
    BINDING *pb;
    int i;
    fBusy = 1;
    for (pb = pbindingFirst; pb; pb = pb->pnext) {
        if (pb->sym == sym) {
            pref = &pb->ref;
            goto done;
        }
    }
    if (!fRecurse)
        goto done;
    for (i = 0; i < cframe; i++) {
        CFrame *pframe = apframe[i];
        if (!pframe->fBusy) {
            pref = pframe->PrefFindBinding(sym, fRecurse);
            if (pref)
                goto done;
        }
    }
done:
    fBusy = 0;
    return pref;
}
