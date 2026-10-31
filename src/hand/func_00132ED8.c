struct CRef { int m_tagk; void *pv; };
struct N;
struct SP { struct N *p; };
struct N { int cref; int x4; struct CRef ref; struct SP sp; };
struct X { int f; struct N *pn; };
extern char D_004520A8[];
struct N *func_00256B48(void);
void Set__3SPNP4NODE(struct SP *psp, struct N *pn);
void __as__3SPMP4NODE(struct SP *psp, struct N *pn);
void func_00256D40(struct SP *psp, int n);
struct CRef *__as__4CRefP4NODE(struct CRef *pref, struct N *pn);
void __as__4CRefP3T19(struct CRef *pref, int n);
void __as__4CRefPv(struct CRef *pref, int n);
void func_00129EC8(struct CRef *pref);
void func_002550F8(void *pv);
void FreeSlotheapPv__FP8SLOTHEAPPv(void *pool, void *pv);
struct SP *func_00132ED8(struct SP *ret, int a1, int a2, struct X *px)
{
    struct SP sp;
    struct N *p;
    Set__3SPNP4NODE(&sp, func_00256B48());
    {
        struct CRef *pref = &sp.p->ref;
        __as__4CRefP4NODE(pref, func_00256B48());
    }
    p = (struct N *)sp.p->ref.pv;
    __as__4CRefP3T19(&p->ref, a2);
    {
        struct N *pn = func_00256B48();
        __as__3SPMP4NODE(&p->sp, pn);
    }
    p = p->sp.p;
    __as__4CRefPv(&p->ref, a1);
    if (px && px->f)
        __as__3SPMP4NODE(&p->sp, px->pn);
    Set__3SPNP4NODE(ret, sp.p);
    {
        struct N *pt = sp.p;
        if (pt && --pt->cref == 0) {
            func_00256D40(&pt->sp, 2);
            func_00129EC8(&pt->ref);
            func_002550F8(pt);
            FreeSlotheapPv__FP8SLOTHEAPPv(D_004520A8, pt);
        }
    }
    return ret;
}
