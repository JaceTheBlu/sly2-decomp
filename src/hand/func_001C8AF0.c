struct G { char pad[0x4764]; int a; int b; };
extern struct G g_sw;
struct H;
extern struct H g_sndmgr;
struct S { char pad[0x190]; int n190; char pad2[0x64]; int n1f8; };
void func_001C8730(struct S *p, int n);
void func_001618B0(struct G *pg);
void func_001FE5F0(struct H *ph, int n, int m);
void func_001C8AF0(struct S *p, int n)
{
    struct G *pg = &g_sw;
    if (pg->a >= pg->b) {
        p->n190 = n;
        func_001C8730(p, 1);
    } else {
        func_001618B0(pg);
        if (p->n1f8 != -1) func_001FE5F0(&g_sndmgr, p->n1f8, 1);
    }
}
