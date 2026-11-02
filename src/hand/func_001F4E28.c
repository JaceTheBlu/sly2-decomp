struct VTE { short d; short p; void (*pfn)(void *, void *); };
struct VT { struct VTE a[55]; };
struct X { char pad[0xC]; struct VT *pvt; };
struct N { void *pv0; struct N *next; int *pn8; struct X *px; };
struct E { char pad[0x60]; struct X *p60; struct N *pn; void *p68; };
struct P { char pad[0xC]; struct VT *pvt; char pad2[0xEC - 0x10]; struct E *pe; };
struct G;
extern struct G g_sw;
void func_001F4BF8(struct P *);
void func_001A7E10(struct G *, void *);
#define VF(q, n, a) (q)->pvt->a[n].pfn((char *)(q) + (q)->pvt->a[n].d, a)
void func_001F4E28(struct P *p)
{
    struct N *pn;
    if (!p->pe) return;
    func_001F4BF8(p);
    for (pn = p->pe->pn; pn; pn = pn->next) {
        struct X *q = p->pe->p60;
        q->pvt->a[54].pfn((char *)q + q->pvt->a[54].d, pn->px);
        pn->px->pvt->a[54].pfn((char *)pn->px + pn->px->pvt->a[54].d, p->pe->p60);
        func_001A7E10(&g_sw, pn->pv0);
        *pn->pn8 = 0;
        pn->pv0 = 0;
    }
    p->pvt->a[54].pfn((char *)p + p->pvt->a[54].d, 0);
    func_001A7E10(&g_sw, p->pe->p68);
    p->pe->p68 = 0;
}
