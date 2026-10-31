typedef struct MSG { int cb; int nKind; } MSG;
void *PvAllocStackClearImpl__FP7SWALLOC(MSG *pmsg);
static inline void *PvAllocMsg(MSG *pmsg, int cb, int nKind) { pmsg->cb = cb; pmsg->nKind = nKind; return PvAllocStackClearImpl__FP7SWALLOC(pmsg); }
struct S { int cdzMax; char pad[0x4C]; int a; int b; int c; int d; void *pv; };
struct S *func_0011A550(struct S *p, int c);
struct S *func_001585D8(struct S *p, int a, int b, int c, int d)
{
    MSG msg;
    func_0011A550(p, a * 2);
    p->a = a;
    p->b = b;
    p->c = c;
    p->d = d;
    msg.nKind = 0x10;
    msg.cb = 0x60 * p->cdzMax;
    p->pv = PvAllocStackClearImpl__FP7SWALLOC(&msg);
    return p;
}
