struct ALLOCREQ { int cb; int nKind; };
class FRAME {
public:
    int a[4];
    FRAME();
    ~FRAME();
};
struct X { char pad[0x54]; int n; char pad2[0xA0 - 0x58]; int fA0; };
struct G { char pad[0x3AFC]; int c; };
extern G g_sw;
extern "C" void *PvAllocStackClearImpl__FP7SWALLOC(ALLOCREQ *preq);
extern "C" int func_0015E9C8(G *pg, int kind, int n, int m, int c, void **apv);
static inline void *PvAllocReq(ALLOCREQ *preq, int cb, int nKind)
{
    preq->cb = cb;
    preq->nKind = nKind;
    return PvAllocStackClearImpl__FP7SWALLOC(preq);
}
static inline int Min(int a, int b) { return a > b ? b : a; }
extern "C" int func_00161660()
{
    int c = 0;
    int cDone = 0;
    FRAME fr;
    ALLOCREQ req;
    G *pg = &g_sw;
    X **apx = (X **)PvAllocReq(&req, pg->c * 4, 0x10);
    int n = func_0015E9C8(pg, 5, 0x85, 0, pg->c, (void **)apx);
    for (int i = 0; i < n; i++) {
        X *px = apx[i];
        if (px->fA0) {
            c++;
            if (px->n == 3)
                cDone++;
        }
    }
    if (!cDone)
        return 0;
    if (cDone == c)
        return 100;
    int nMax = 99; int pct = cDone * 100 / c; int nRet = 1; if (pct > 0) nRet = Min(pct, nMax); return nRet;
}
