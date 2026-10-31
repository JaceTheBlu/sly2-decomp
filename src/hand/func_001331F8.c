struct CRef { int m_tagk; void *pv; };
struct N;
struct SP { struct N *p; };
struct N { int cref; int x4; struct CRef ref; struct SP sp; };
struct P { void *p0; };
struct CLOCK { float t; };
extern struct CLOCK D_002DDED0;
extern char g_sw[];
extern char D_004520A8[];
extern int D_0027A1D8[];
extern int D_0027A10C[];
int func_00127DB8(void *p, int k, int n);
struct CRef *RefSetArgListFromPvs__FiP4OTYPPPv(struct CRef *ret, int x, int *pn, int y);
struct SP *func_00132ED8(struct SP *ret, struct P *p, int k, struct CRef *pref);
void func_00133040(void *pg, struct P *p, struct N *pn, float t);
void func_00133000(struct P *p, struct N *pn, void *p0, int z);
void func_00256D40(struct SP *psp, int n);
void func_00129EC8(struct CRef *pref);
void func_002550F8(void *pv);
void FreeSlotheapPv__FP8SLOTHEAPPv(void *pool, void *pv);
void func_001331F8(struct P *p, int k, int f, int x, int y, int z)
{
    if (p->p0 && func_00127DB8(p->p0, k, 1)) {
        struct CRef ref;
        struct SP sp;
        RefSetArgListFromPvs__FiP4OTYPPPv(&ref, x, &D_0027A10C[D_0027A1D8[k]], y);
        func_00132ED8(&sp, p, k, &ref);
        if (f)
            func_00133040(g_sw, p, sp.p, D_002DDED0.t);
        else
            func_00133000(p, sp.p, p->p0, z);
        {
            struct N *pt = sp.p;
            if (pt && --pt->cref == 0) {
                func_00256D40(&pt->sp, 2);
                func_00129EC8(&pt->ref);
                func_002550F8(pt);
                FreeSlotheapPv__FP8SLOTHEAPPv(D_004520A8, pt);
            }
        }
        func_00129EC8(&ref);
    }
}
