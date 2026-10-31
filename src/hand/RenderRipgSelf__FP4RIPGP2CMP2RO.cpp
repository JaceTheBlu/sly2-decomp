#include "clock.h"
struct DL { void *head; void *tail; int ibDle; };
struct DLI { DL *m_pdl; void **m_ppv; int m_ibDle; DLI *m_pdliNext; };
extern DLI *g_pdliFirst;
extern CLOCK g_clock;
struct VTE { short d; short pad; void (*pf)(); };
struct RIP { char pad[0x14]; float tStart; char p1[0xEC - 0x18]; VTE *vt; };
struct RIPG { char pad[0x15C]; DL dl; };
struct CM;
struct RO;
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
void RenderRipgSelf(RIPG *pripg, CM *pcm, RO *pro)
{
    DLI dli;
    RIP *prip;
    InitDli(&dli, &pripg->dl);
    while ((prip = (RIP *)PvNextDli(&dli)) != 0) {
        if (g_clock.t <= prip->tStart) continue;
            ((void (*)(void *))prip->vt[6].pf)((char *)prip + prip->vt[6].d);
    }
    g_pdliFirst = dli.m_pdliNext;
}
