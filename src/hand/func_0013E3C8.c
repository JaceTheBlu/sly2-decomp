struct VT { short d; short pad; void *pfn; };
struct LO { char pad[0xC]; struct VT *pvt; void *psw; int x14; int oid; int x1C; int x20; int x24; int x28; signed char x2C; char x2D; long k:4; long :8; unsigned int f:1; };
struct CLS { int x0; int x4; int x8; int xC; struct LO *(*pfnNew)(void); };
struct G { char pad[0x39E4]; struct LO **pplo; };
extern struct CLS D_002BAAE8[];
extern struct G g_sw;
void *func_001FFA40(struct G *pg, int n, struct LO *plo);
void func_00256EE0(struct LO *plo, void *pv);
void *func_0015E380(struct G *pg, int oid);
void *func_0015E3A8(struct G *pg, int cid);
void func_0011A070(void *pdl, struct LO *plo);
int func_001A61A0(struct LO *plo);
#define VCALL(p, n) ((void (*)(void *))(p)->pvt[n].pfn)((char *)(p) + (p)->pvt[n].d)
struct LO *func_0013E3C8(int cid, void *psw, int oid, int n)
{
    struct G *pg; struct LO *plo = (D_002BAAE8 + cid)->pfnNew();
    plo->psw = psw;
    plo->oid = oid;
    pg = &g_sw;
    func_00256EE0(plo, func_001FFA40(pg, n, plo));
    func_0011A070(func_0015E380(pg, oid), plo);
    func_0011A070(func_0015E3A8(pg, cid), plo);
    VCALL(plo, 7);
    if (plo->f)
        VCALL(plo, 11);
    if (func_001A61A0(plo))
        VCALL(plo, 23);
    if (pg->pplo)
        *pg->pplo++ = plo;
    return plo;
}
