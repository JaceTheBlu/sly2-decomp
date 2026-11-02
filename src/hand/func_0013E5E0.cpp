class X;
typedef void (X::*PMF)(void *);
struct D { int id; PMF pmf; };
extern "C" char g_sw[];
extern "C" void *PloFindSwObject__FP2SWi3OIDP2LO(void *, int, int, X *);
extern "C" void func_0013E5E0(X *p, D *pd)
{
    void *pv = PloFindSwObject__FP2SWi3OIDP2LO(g_sw, 4, pd->id, p);
    (p->*(pd->pmf))(pv);
}
