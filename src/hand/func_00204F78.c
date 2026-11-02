struct G;
extern struct G g_sw;
struct O { char pad[0x10]; struct O *pParent; char p2[0xEC - 0x14]; void *pvEC; };
void *func_001A5BF0(void *pv);
void func_00133A38(struct G *pg, void *a, void *b, int n);
void func_001F4BF8(struct O *p);
void func_00204F78(struct O *p, void *pv, int f)
{
    struct O *o = func_001A5BF0(pv);
    while (o && !o->pvEC) o = o->pParent;
    if (p->pvEC && o && o->pvEC) func_00133A38(&g_sw, p->pvEC, o->pvEC, f ? 1 : 2);
    func_001F4BF8(p);
}
