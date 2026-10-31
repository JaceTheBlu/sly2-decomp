#include "clock.h"
struct DL { void *pvFirst; void *pvLast; int ibDle; };
struct DLI { struct DL *pdl; void **ppv; int ibDle; struct DLI *pdliNext; };
extern struct DLI *g_pdliFirst;
extern struct CLOCK g_clock;
struct E { char pad[0x4C]; float t; };
struct P { char pad[0x4118]; char pool[0x18]; struct DL dl; };
void func_0011A2E8(struct DL *, void *);
void FreeSlotheapPv__FP8SLOTHEAPPv(void *, void *);
static inline void InitDli(struct DLI *pdli, struct DL *pdl)
{
    pdli->pdl = pdl;
    pdli->ppv = (void **)pdl;
    pdli->ibDle = pdl->ibDle;
    pdli->pdliNext = g_pdliFirst;
    g_pdliFirst = pdli;
}
static inline void *PvNextDli(struct DLI *pdli)
{
    void *pv = *pdli->ppv;
    pdli->ppv = (void **)((char *)pv + pdli->ibDle);
    return pv;
}
void func_001F77C0(struct P *p)
{
    struct DLI dli;
    struct E *pe;
    InitDli(&dli, &p->dl);
    while ((pe = PvNextDli(&dli)) != 0) {
        if (g_clock.t < pe->t + 0.25f) continue;
        func_0011A2E8(&p->dl, pe);
        FreeSlotheapPv__FP8SLOTHEAPPv(p->pool, pe);
    }
    g_pdliFirst = dli.pdliNext;
}
