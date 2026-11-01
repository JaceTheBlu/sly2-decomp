typedef struct MSG { int cb; int nKind; } MSG;
void *PvAllocSwCopyImpl__FP7SWALLOCPv(MSG *pmsg, void *pv);
static inline void *PvReallocMsg(MSG *pmsg, void *pv, int cb, int nKind) { pmsg->cb = cb; pmsg->nKind = nKind; return PvAllocSwCopyImpl__FP7SWALLOCPv(pmsg, pv); }
struct S { int pad[4]; void *p10; char pad2[0xE0 - 0x14]; int c; void **apv; };
void CloneAlo__FP3ALOT0(struct S *p, void *pv);
void *PloCloneLo(void *pv, void *p10);
void CloneCid31(struct S *p, void *pv)
{
    MSG msg;
    int i;
    CloneAlo__FP3ALOT0(p, pv);
    p->apv = PvReallocMsg(&msg, p->apv, p->c * 4, 0x10);
    for (i = 0; i < p->c; i++)
        p->apv[i] = PloCloneLo(p->apv[i], p->p10);
}
