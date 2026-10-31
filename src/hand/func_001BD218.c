typedef struct DL { void *head; void *tail; int ibDle; } DL;
typedef struct DLI { DL *m_pdl; void **m_ppv; int m_ibDle; struct DLI *m_pdliNext; } DLI;
extern DLI *g_pdliFirst;
struct VE { short d; short pad; void (*pfn)(); };
struct S { char pad[0xC]; struct VE *vt; char pad1[0x1C4 - 0x10]; DL dl; char pad2[0x1D8 - 0x1D0]; int x1D8; };
extern char D_003E1A4C[], D_003E1A40[];
void func_0011A2E8(DL *pdl, struct S *pv);
int func_0011A380(void *pdl, struct S *pv);
void func_0011A220(void *pdl, struct S *pv);
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
void func_001BD218(struct S *p)
{
    DLI dli;
    struct S *pv;
    InitDli(&dli, &p->dl);
    while ((pv = PvNextDli(&dli)) != 0) {
        func_0011A2E8(&p->dl, pv);
        pv->x1D8 = 0;
        if (!func_0011A380(D_003E1A4C, pv)) func_0011A220(D_003E1A4C, pv);
    }
    ((void (*)(void *))p->vt[9].pfn)((char *)p + p->vt[9].d);
    func_0011A220(D_003E1A40, p);
    g_pdliFirst = dli.m_pdliNext;
}
