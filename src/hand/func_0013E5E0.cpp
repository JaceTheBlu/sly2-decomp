class X;
typedef void (X::*PMF)(void *);
struct D { int id; PMF pmf; };
extern "C" char g_sw[];
extern "C" void *func_0015E938(void *, int, int, X *);
extern "C" void func_0013E5E0(X *p, D *pd)
{
    void *pv = func_0015E938(g_sw, 4, pd->id, p);
    (p->*(pd->pmf))(pv);
}
