typedef unsigned long ulong;
struct O { char pad[0x148]; long bits; };
struct N { int x0; struct O *po; int x8; struct N *next; };
struct G;
extern struct G g_sw;
void func_00229738(struct O *po, struct N *pn);
void AddSoXa__FP2SOP2XA(struct O *po, struct N *pn);
void func_002296C0(struct G *pg, struct N *pn);
void func_00228D20(void *pv, struct N **ppn)
{
    struct N *pn = *ppn;
    struct N *pnFree = 0;
    while (pn) {
        struct O *po = pn->po;
        struct N *pnNext = pn->next;
        long b = po->bits;
        if (((int)(b >> 31) & 1) != ((b >> 32) & 1)) {
            if (b & 0x80000000L)
                func_00229738(po, pn);
            else
                AddSoXa__FP2SOP2XA(po, pn);
        }
        if (pn->po->bits & 0x100000000L) {
            ppn = &pn->next;
        } else {
            *ppn = pnNext;
            pn->next = pnFree;
            pnFree = pn;
        }
        {
            long c = pn->po->bits & ~0x100000000L;
            pn->po->bits = c & ~0x80000000L;
        }
        pn = pnNext;
    }
    func_002296C0(&g_sw, pnFree);
}
