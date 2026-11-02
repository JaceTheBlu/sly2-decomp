#include "dl.h"
extern DLI *g_pdliFirst;
struct RIP;
struct RIPG { char pad[0x10]; int x10; char p1[0xEC - 0x14]; void *xEC; char p2[0x15C - 0xF0]; DL dl; };
struct SW { char pad[0x403C]; char pool[0x30]; RIPG *x406C; };
extern SW g_sw;
extern "C" {
void func_001CE980(RIP *prip);
void OnSoRemove__FP2SO(RIPG *p);
void func_001337D0(SW *psw, void *pv);
void func_001A57A8(RIPG *p);
void *func_0015E3A8(SW *psw, int n);
void func_0011A118(void *pl, RIPG *p);
void func_001A53E0(RIPG *p);
void FreeSlotheapPv__FP8SLOTHEAPPv(void *pool, void *pv);
}
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
void OnRipgRemove(RIPG *pripg)
{
    DLI dli;
    RIP *prip;
    SW *psw;
    InitDli(&dli, &pripg->dl);
    while ((prip = (RIP *)PvNextDli(&dli)) != 0) func_001CE980(prip);
    psw = &g_sw;
    if (pripg == psw->x406C) psw->x406C = 0;
    OnSoRemove__FP2SO(pripg);
    if (pripg->xEC) {
        func_001337D0(psw, pripg->xEC);
        pripg->xEC = 0;
    }
    func_001A57A8(pripg);
    func_0011A118(func_0015E3A8(psw, 0x57), pripg);
    if (!pripg->x10) func_001A53E0(pripg);
    FreeSlotheapPv__FP8SLOTHEAPPv(psw->pool, pripg);
    g_pdliFirst = dli.m_pdliNext;
}
