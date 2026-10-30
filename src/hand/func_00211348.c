struct T { char pad[0xCC]; int a[1]; };
extern struct G g_sw;
int func_0013E368(struct G *g, int x);
void func_0021ED58(void *p, int v);
void func_00211348(void *p, int i, struct T *t)
{
    func_0021ED58(p, func_0013E368(&g_sw, t->a[i]));
}
