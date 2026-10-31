#include "dl.h"
extern DLI *g_pdliFirst;     /* g_pdliFirst */
extern char D_002DEAF0[];
struct S { char pad[0x10]; int f10; char pad2[0x448 - 0x14]; DL dl; };
void func_00139098(void *);
void func_001A5848(struct S *);
void func_001A57A8(struct S *);
void func_001A53E0(struct S *);
void func_0011A220(void *, struct S *);
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
void func_00139250(struct S *p) {
    DLI dli;
    void *pv;
    InitDli(&dli, &p->dl);
    while ((pv = PvNextDli(&dli)) != 0) func_00139098(pv);
    func_001A5848(p);
    func_001A57A8(p);
    if (!p->f10) func_001A53E0(p);
    func_0011A220(D_002DEAF0, p);
    g_pdliFirst = dli.m_pdliNext;
}
