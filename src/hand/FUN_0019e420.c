typedef struct DL { void *head; void *tail; int ibDle; } DL;
typedef struct DLI { DL *m_pdl; void **m_ppv; int m_ibDle; struct DLI *m_pdliNext; } DLI;
extern DLI *g_pdliFirst;
struct CLOCK { float t, dt; };
extern struct CLOCK D_002DDED0;
struct VTE { short d; short pad; void (*pf)(); };
struct RIP { char pad[0x14]; float tStart; char p1[0xEC - 0x18]; struct VTE *vt; };
struct RIPG { char pad[0xC]; struct VTE *vt; char p1[0x15C - 0x10]; DL dl; };
void func_001CE9C0(struct RIP *prip);
void ReleaseRip__FP3RIP(struct RIP *prip);
int func_001A61A0(struct RIPG *p);
int func_0011A3B0(DL *pdl);
void func_001CE2E8(struct RIPG *p);
static inline void InitDli(DLI *pdli, DL *pdl)
{
    pdli->m_pdl = pdl;
    pdli->m_ppv = (void **)pdl;
    pdli->m_ibDle = pdl->ibDle;
    pdli->m_pdliNext = g_pdliFirst;
    g_pdliFirst = pdli;
}
static inline void *PvNextDli(DLI *pdli)
{
    void *pv = *pdli->m_ppv;
    pdli->m_ppv = (void **)((char *)pv + pdli->m_ibDle);
    return pv;
}
void FUN_0019e420(struct RIPG *pripg)
{
    DLI dli;
    struct RIP *prip;
    InitDli(&dli, &pripg->dl);
    while ((prip = (struct RIP *)PvNextDli(&dli)) != 0) {
        if (D_002DDED0.t <= prip->tStart) continue;
        func_001CE9C0(prip);
        ((void (*)(void *))prip->vt[5].pf)((char *)prip + prip->vt[5].d);
        ReleaseRip__FP3RIP(prip);
    }
    if (!func_001A61A0(pripg) || func_0011A3B0(&pripg->dl))
        ((void (*)(void *))pripg->vt[9].pf)((char *)pripg + pripg->vt[9].d);
    else
        func_001CE2E8(pripg);
    g_pdliFirst = dli.m_pdliNext;
}
