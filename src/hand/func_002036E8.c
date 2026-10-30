struct G;
extern struct G g_sw;
struct S { char pad[0xEC]; void *o; int n; };
void func_00164640(void *o, int n, void *p);
char *func_001C4840(struct G *pg);
int func_00132B10(void *o, int n);
void func_0019D948(void *pv);
void func_002036E8(struct S *p, int n)
{
    if (p->o) {
        char *o;
        func_00164640(p->o, 2, p);
        o = func_001C4840(&g_sw);
        if (o && func_00132B10(o, 0x34)) func_0019D948(o + 0xF24);
    } else p->n = n;
}
