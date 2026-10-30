struct P { char pad[0xC]; void *pvt; char pad2[0x60 - 0x10]; int n60; char pad3[0x70 - 0x64]; float a[6]; char pad4[0x3B8 - 0x88]; int n3B8; };
struct G { char pad[0x58]; int n58; char pad2[0x15C - 0x5C]; float a[1]; };
extern struct G g_sndmgr;
extern char D_002D9BE0[];
void func_001FAFD0(struct P *);
void func_001FB658(struct P *, int, int);
int func_001FD080(struct G *, int);
void func_001FB018(struct P *);
struct P *func_001FC190(struct P *p, int n, int m)
{
    int i;
    struct G *pg;
    func_001FAFD0(p);
    p->n60 = n;
    p->pvt = D_002D9BE0;
    p->n3B8 = m;
    for (i = 0; i < 6; i++) p->a[i] = 1.0f;
    pg = &g_sndmgr;
    func_001FB658(p, 0x801, 0x801);
    if (*(pg->a + func_001FD080(pg, p->n60)) == 0.0f) func_001FB018(p);
    if (pg->n58) func_001FB018(p);
    return p;
}
