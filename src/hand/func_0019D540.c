struct G;
extern struct G g_sw;
struct Q { int x0; };
struct P { struct Q *x0; int x4; void *x8; void *xc; int x10; void *x14; };
int func_00132B10(int a, int b);
void *func_0015E938(struct G *g, int k, int oid, int z);
void func_00201DC8(void *p);
void func_0019DCA0(struct P *p, void *q);
void func_0019D540(struct P *p)
{
    if (func_00132B10(p->x0->x0, 0x35)) {
        p->x8 = func_0015E938(&g_sw, 0x405, 0x35F, 0);
        p->xc = func_0015E938(&g_sw, 0x405, 0x368, 0);
    } else if (func_00132B10(p->x0->x0, 0x37)) {
        p->x8 = func_0015E938(&g_sw, 0x405, 0x360, 0);
        p->xc = func_0015E938(&g_sw, 0x405, 0x369, 0);
    } else if (func_00132B10(p->x0->x0, 0x36)) {
        p->x8 = func_0015E938(&g_sw, 0x405, 0x361, 0);
        p->xc = func_0015E938(&g_sw, 0x405, 0x36A, 0);
    }
    if (p->x14)
        func_00201DC8(p->x14);
    func_0019DCA0(p, p->xc);
}
