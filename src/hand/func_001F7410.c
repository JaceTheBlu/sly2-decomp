typedef int qword __attribute__((mode(TI)));
struct O { char pad[0x14]; short s14; short pad2; int n18; };
struct H { struct O *po; int pad; void *p8; void *pC; qword q10; qword q20; qword q30; };
struct N { struct H h[2]; char pad[0xAC - 0x80]; struct N *next; };
struct E { char pad[0x6C]; struct N *pn; };
struct P { char pad[0xEC]; struct E *pe; };
struct M { void *p0; void *p4; void *p8; int nC; int n10; int pad[3]; qword q20; qword q30; char pad2[0x60 - 0x40]; };
struct G;
extern struct G g_sw;
void *func_001F7530(void *, int);
void func_002333B4(void *, int, int);
int func_001F7598(struct M *);
void func_001A7E10(struct G *, void *);
void func_001F7410(struct P *p)
{
    struct N *pn;
    for (pn = p->pe->pn; pn; pn = pn->next) {
        int i = pn->h[0].p8 != p;
        struct H *ph = (struct H *)((char *)pn + (i << 6));
        if (ph->po->n18) {
            struct H *pot = (struct H *)((char *)pn + ((1 - i) << 6));
            void *r = func_001F7530(pot->pC, ph->po->n18);
            if (r) {
                struct M m;
                func_002333B4(&m, 0, 0x60);
                m.p0 = p;
                m.p4 = ph->po;
                m.p8 = r;
                m.nC = ph->po->n18;
                m.n10 = ph->po->s14;
                m.q20 = pot->q10;
                m.q30 = ph->q30;
                func_001F7598(&m);
                if (!p->pe) break;
            }
        }
    }
    if (p->pe) {
        func_001A7E10(&g_sw, p->pe->pn);
        p->pe->pn = 0;
    }
}
