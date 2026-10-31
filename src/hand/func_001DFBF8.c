struct MSG { int cb; int nKind; };
struct S { char pad[0x54]; void *pv; int c; char p1[0x80-0x5C]; int f80; };
void func_001A6730(struct S *p);
void *PvAllocSwCopyImpl__FP7SWALLOCPv(struct MSG *pmsg, void *pv);
static inline void *PvReallocMsg(struct MSG *pmsg, int cb, int nKind, void *pv) { pmsg->cb = cb; pmsg->nKind = nKind; return PvAllocSwCopyImpl__FP7SWALLOCPv(pmsg, pv); }
void func_001DFBF8(struct S *p) {
    struct MSG msg;
    func_001A6730(p);
    if (p->f80) p->pv = PvReallocMsg(&msg, p->c * 0x50, 0x10, p->pv);
}
