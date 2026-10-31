struct MSG { int cb; int nKind; };
struct S { char pad[0xD4]; int c; void *pv; };
void *PvAllocSwImpl__Fi(struct MSG *pmsg);
static inline void *PvAllocMsg(struct MSG *pmsg, int cb, int nKind) { pmsg->cb = cb; pmsg->nKind = nKind; return PvAllocSwImpl__Fi(pmsg); }
void func_001D8600(struct S *p, int c) {
    struct MSG msg;
    p->c = c;
    p->pv = PvAllocMsg(&msg, c << 4, 0x10);
}
