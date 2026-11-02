#include "cref.h"
struct NODE { int x0, x4; CRef ref; NODE *pnext; };
struct P { char pad[0xC]; struct { char pad[0x10]; NODE *pargs; } *pv; };
struct FRAME {
    int cref;
    ~FRAME();
};
struct SPF {
    FRAME *p;
    SPF() { p = 0; }
    ~SPF() { FRAME *pf = p; if (pf && --pf->cref == 0) delete pf; }
    void operator=(FRAME *pf);
};
extern "C" {
FRAME *func_00256DD0();
CRef func_00127838(NODE *p, FRAME *pframe);
CRef RefAddBinding__6CFrameUiP4CRef(FRAME *pframe, int sym, CRef *pref);
void func_00127B18(FRAME *pframe, FRAME *pframeParent);
CRef func_00126DB8(P *p, FRAME *pframe);
}
CRef func_00126DB8(P *p, FRAME *pframe)
{
    CRef ref;
    CRef refVal;
    CRef refT;
    SPF spf;
    NODE *pargs = p->pv->pargs;
    NODE *pn;
    if (pargs->ref.m_tagk == 0x1F) {
        FRAME *pfNew = func_00256DD0();
        spf = pfNew;
        for (pn = (NODE *)pargs->ref.m_p; pn; pn = pn->pnext) {
            NODE *pb = (NODE *)pn->ref.m_p;
            refVal = func_00127838(pb->pnext, pframe);
            refT = RefAddBinding__6CFrameUiP4CRef(spf.p, pb->ref.m_tag, &refVal);
        }
        func_00127B18(spf.p, pframe);
    } else {
        spf = pframe;
    }
    NODE *pq;
    for (pq = pargs->pnext; pq; pq = pq->pnext)
        ref = func_00127838(pq, spf.p);
    return ref;
}
