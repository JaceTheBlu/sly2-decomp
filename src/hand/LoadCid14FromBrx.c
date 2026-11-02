struct MSG { int cb; int nKind; };
struct S { char pad[0xE8]; int c; char pad2[0x1EC - 0xEC]; void *p; };
void LoadCid10FromBrx(struct S *p);
void *PvAllocSwClearImpl__FP7SWALLOC(struct MSG *pmsg);
static __inline__ void *PvAllocMsg(struct MSG *pmsg, int cb, int nKind) { pmsg->cb = cb; pmsg->nKind = nKind; return PvAllocSwClearImpl__FP7SWALLOC(pmsg); }
void LoadCid14FromBrx(struct S *p)
{
    struct MSG msg;
    LoadCid10FromBrx(p);
    p->p = PvAllocMsg(&msg, (p->c << 4) - 0x10, 0x10);
}
