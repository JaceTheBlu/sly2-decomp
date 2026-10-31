#include "cref.h"
struct OBJ;
struct PRM { int a; int k; int rest[8]; };
extern "C" {
extern char D_004520A8[];
CRef *SetTag__4CRef4TAGK(CRef *pref, int tagk);
void *func_002333B4(void *p, int c, int n);
OBJ *func_00256B48(void);
void func_001FFD98(CRef *ret, void *b, PRM *prm);
CRef *func_00129658(CRef *pref, CRef *prefSrc); /* CRef::operator= returns *this */
void func_00129EC8(CRef *pref);
void func_002550F8(OBJ *p);
void FreeSlotheapPv__FP8SLOTHEAPPv(void *pool, OBJ *p);
void __4CRefP4NODE(CRef *pref, OBJ *p);
CRef *RefSetArgListFromPvs__FiP4OTYPPPv(CRef *ret, int c, int *a, void **b);
}
class SP {
public:
    OBJ *p;
    SP() { p = 0; }
    SP(OBJ *q);
    void Set(OBJ *q);
    void Dtor(int n);
    ~SP();
} __attribute__((aligned(16)));
extern "C" {
void Set__3SPNP4NODE(SP *pp, OBJ *p);
void __as__3SPMP4NODE(SP *pp, OBJ *p);
void func_00256D40(SP *p, int n);
}
struct CREFA { CRef r; } __attribute__((aligned(16)));
struct OBJ { int cref; int pad; CRef ref; SP next; };
inline SP::SP(OBJ *q) { Set__3SPNP4NODE(this, q); }
inline void SP::Set(OBJ *q) { __as__3SPMP4NODE(this, q); }
inline SP::~SP()
{
    OBJ *q = p;
    if (q) {
        if (--q->cref == 0) {
            func_00256D40(&q->next, 2);
            func_00129EC8(&q->ref);
            func_002550F8(q);
            FreeSlotheapPv__FP8SLOTHEAPPv(D_004520A8, q);
        }
    }
}

CRef *RefSetArgListFromPvs__FiP4OTYPPPv(CRef *ret, int c, int *a, void **b)
{
    if (c == 0) {
        SetTag__4CRef4TAGK(ret, 0);
        return ret;
    }
    PRM prm;
    SP list;
    func_002333B4(&prm, 0, sizeof(prm));
    prm.k = 2;
    SP *ppTail = &list;
    for (int i = 0; i < c; i++) {
        void *pb = b[i];
        prm.a = a[i];
        SP nw(func_00256B48());
        CRef *pr = &nw.p->ref;
        CREFA ref;
        func_001FFD98(&ref.r, pb, &prm);
        func_00129658(pr, &ref.r);
        func_00129EC8(&ref.r);
        ppTail->Set(nw.p);
        ppTail = &nw.p->next;
    }
    __4CRefP4NODE(ret, list.p);
    return ret;
}
