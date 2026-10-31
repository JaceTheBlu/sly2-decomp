#include "dl.h"
extern DLI *g_pdliFirst;
struct DZ { int n0; int pad4[3]; float g10; int pad14; int f18; int pad1C; DZ *pdzNext; };
struct DZG { int pad0[3]; DL dlC; int pad18[6]; DL dl30; int c3C; };
struct XP; struct SO;
extern "C" {
int func_00158958(DZG *, DZ *);
void func_00158728(DZG *, int, DZ *, int);
void func_0011A2E8(DL *, void *);
void func_0011A220(DL *, void *);
void func_0011A770(DZG *, DZ *);
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
void SolveDzg(DZG *pdzg, int a, int b, XP **ppxp, int *pn, SO ***pppso)
{
    DLI dli;
    DLI dliUnused;
    DZ *pdz;
    InitDli(&dli, &pdzg->dl30);
    while ((pdz = (DZ *)PvNextDli(&dli)) != 0) {
        if (pdz->n0 == 1) {
            if (!pdz->f18)
                func_00158728(pdzg, a, pdz, func_00158958(pdzg, pdz));
            func_0011A2E8(&pdzg->dl30, pdz);
            func_0011A220(&pdzg->dlC, pdz);
            pdzg->c3C++;
        }
    }
    func_0011A770(pdzg, 0);
    g_pdliFirst = dli.m_pdliNext;
    for (;;) {
        DZ *pdzBest = 0;
        float gMin = -0.01f;
        for (DZ *pdzT = (DZ *)pdzg->dl30.head; pdzT; pdzT = pdzT->pdzNext) {
            if (pdzT->g10 < gMin) {
                gMin = pdzT->g10;
                pdzBest = pdzT;
            }
        }
        if (!pdzBest)
            break;
        if (!pdzBest->f18)
            func_00158728(pdzg, a, pdzBest, func_00158958(pdzg, pdzBest));
        func_0011A770(pdzg, pdzBest);
    }
}
