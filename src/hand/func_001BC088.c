struct MSG { int cb; int nKind; };
struct S { char pad[0xE8]; int c; char pad2[0x1EC - 0xEC]; void *p; };
void func_001E5DF8(struct S *p);
void *PvAllocSwClearImpl__FP7SWALLOC(struct MSG *pmsg);
static __inline__ void *PvAllocMsg(struct MSG *pmsg, int cb, int nKind) { pmsg->cb = cb; pmsg->nKind = nKind; return PvAllocSwClearImpl__FP7SWALLOC(pmsg); }
void func_001BC088(struct S *p)
{
    struct MSG msg;
    func_001E5DF8(p);
    p->p = PvAllocMsg(&msg, (p->c << 4) - 0x10, 0x10);
}
