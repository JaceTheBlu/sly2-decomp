#include "cref.h"
struct W;
extern char D_004520D0[];
extern "C" {
void FreeSlotheapPv__FP8SLOTHEAPPv(void *pheap, void *pv);
void func_00255438(void *pv);
W *func_00257340();
CRef func_00129BC8(CRef *pref, void *a, void *b);
}
struct SPM {
    W *p;
    ~SPM();
    SPM &operator=(W *pw);
};
struct W {
    int cref;
    int x4;
    int x8;
    CRef ref;
    SPM pnext;
    void SetNext(W *pw) { pnext = pw; }
    void operator delete(void *pv) { func_00255438(pv); FreeSlotheapPv__FP8SLOTHEAPPv(D_004520D0, pv); }
};
struct SPW {
    W *p;
    void Set(W *pw);
    SPW() {}
    SPW(W *pw) { Set(pw); }
    SPW(const SPW &);
    ~SPW() { W *pw = p; if (pw && --pw->cref == 0) delete pw; }
    W *operator->() { return p; }
};
extern "C" SPW func_0012B0E8(W *src, void *a, void *b);
SPW func_0012B0E8(W *src, void *a, void *b)
{
    SPW sp;
    sp.Set(func_00257340());
    sp->x8 = src->x8;
    sp->ref = func_00129BC8(&src->ref, a, b);
    if (src->pnext.p)
        sp->SetNext(func_0012B0E8(src->pnext.p, a, b).p);
    return SPW(sp.p);
}
