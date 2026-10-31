typedef struct MSG { int cb; int nKind; } MSG;
void *PvAllocSwClearImpl__FP7SWALLOC(MSG *pmsg);
static inline void *PvAllocMsg(MSG *pmsg, int cb, int nKind) { pmsg->cb = cb; pmsg->nKind = nKind; return PvAllocSwClearImpl__FP7SWALLOC(pmsg); }
struct S { char pad[0x1014]; void *pv; int n; };
void func_002039C0(struct S *p, void *pv);
void func_001553F0(struct S *p, void *pv)
{
    MSG msg;
    p->pv = PvAllocMsg(&msg, 0x480, 0x10);
    func_002039C0(p, pv);
    p->n = 0x7FFFFFFF;
}
