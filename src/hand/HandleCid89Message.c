struct VTE { short d; short pad; void (*pfn)(); };
struct O { int x0, x4, x8; struct VTE *vt; };
struct N { int x0; struct O *po; int x8; struct N *next; };
struct S { char pad[0x150]; struct N *pn; };
struct MSG { struct S *p; struct O *po; };
struct G;
extern struct G g_sw;
void RemoveSoXa__FP2SOP2XA(struct O *po, struct N *pn);
void FreeSwXaList__FP2SWP2XA(struct G *pg, struct N *pn);
void func_00133590(struct S *p, int k, struct O *q);
void HandleCid89Message(struct S *p, int k, struct O *q)
{
    if (k == 1 && q != (struct O *)p) {
        struct MSG msg;
        struct N **ppn = &p->pn;
        struct N *pn = *ppn;
        if (pn) {
            if (pn->po == q) {
                *ppn = pn->next;
            } else {
                for (;;) {
                    struct N *pnPrev = *ppn;
                    pn = pnPrev->next;
                    ppn = &pnPrev->next;
                    if (!pn) break;
                    if (pn->po == q) {
                        pnPrev->next = pn->next;
                        break;
                    }
                }
            }
        }
        msg.p = p;
        msg.po = pn->po;
        if (pn) {
            pn->next = 0;
            RemoveSoXa__FP2SOP2XA(pn->po, pn);
            FreeSwXaList__FP2SWP2XA(&g_sw, pn);
        }
        msg.po->vt[4].pfn((char *)msg.po + msg.po->vt[4].d, 5, &msg);
    }
    func_00133590(p, k, q);
}
