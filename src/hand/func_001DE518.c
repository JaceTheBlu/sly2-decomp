struct MSG { int cb; int nKind; };
struct S { char pad[0x198]; int c; void *pv; };
void CloneCid48(struct S *p);
void *PvAllocSwCopyImpl__FP7SWALLOCPv(struct MSG *pmsg, void *pv);
static inline void *PvReallocMsg(struct MSG *pmsg, int cb, int nKind, void *pv) { pmsg->cb = cb; pmsg->nKind = nKind; return PvAllocSwCopyImpl__FP7SWALLOCPv(pmsg, pv); }
void func_001DE518(struct S *p) {
    struct MSG msg;
    CloneCid48(p);
    p->pv = PvReallocMsg(&msg, p->c * 0x150, 0x10, p->pv);
}
