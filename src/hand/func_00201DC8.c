extern char g_sw[];
struct S { char pad[0x30]; int n30; int a34[16]; char pad2[0xA4 - 0x74]; int nA4; int *pA8; int nAC; int nB0; };
int func_00132B10(int a, int b);
int func_0015E938(void *p, int a, int b, int c);
int func_0015E9C8(void *p, int a, int b, int c, int d, int *e);
void func_00201E88(struct S *p);
void func_00201DC8(struct S *p)
{
    if (func_00132B10(*p->pA8, 0x35)) {
        p->nAC = func_0015E938(g_sw, 0x405, 0x362, 0);
        p->nB0 = func_0015E938(g_sw, 0x405, 0x365, 0);
    }
    p->nA4 = func_0015E938(g_sw, 0x405, 0x602, 0);
    p->n30 = func_0015E9C8(g_sw, 0x405, 0x2E, 0, 16, p->a34);
    func_00201E88(p);
}
