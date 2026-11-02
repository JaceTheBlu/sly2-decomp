struct G { char pad[0x3B0]; int a; };
struct S { char pad[0x16C]; void *p; };
extern struct G g_cm;
void func_00221268(void *p, int f);
void func_0014E328(struct G *pg, int n, void *pv, void *p, int m);
void func_0014E4C8(struct G *pg, int a, int b, void *c, void *d, int e);
void func_001C3FF0(struct S *p, int f)
{
    if (f) {
        if (p->p) func_00221268(p->p, 1);
        else func_0014E328(&g_cm, 1, &g_cm.a, p, 0);
    } else {
        if (p->p) func_00221268(p->p, 0);
        else func_0014E4C8(&g_cm, 0xF, 1, &g_cm.a, p, 0);
    }
}
