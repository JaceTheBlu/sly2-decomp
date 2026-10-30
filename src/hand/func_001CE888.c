struct R { int a, b; void *p8; };
struct G { char pad[0x4054]; char pool[4]; };
struct Q { char pad[0x15C]; char dl[4]; };
extern char g_sw[];
struct Q *func_001CDCD0(void *pg, int n);
void *func_0011CCC0(void *pool);
struct R *func_001CE6D0(void *pv, void *a);
void func_0011A220(void *pdl, void *pv);
void func_001CE9C0(struct R *r);
struct R *func_001CE888(struct G *p, void *a, struct Q *q)
{
    void *pv;
    struct R *r;
    if (!q) q = func_001CDCD0(g_sw, 0);
    if (!q) return 0;
    pv = func_0011CCC0(p->pool);
    if (pv) {
    r = func_001CE6D0(pv, a);
    r->p8 = q;
    func_0011A220(q->dl, r);
    func_001CE9C0(r);
    return r; }
    return 0;
}
