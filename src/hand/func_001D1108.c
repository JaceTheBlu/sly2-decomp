struct O { char p0[8]; int *pn; char p1[0xF0-0xC]; int oid; float gF4; };
extern struct G g_sw;
void func_001CE9B8(struct O *p, struct O *q);
int func_0015E938(struct G *g, int k, int oid, int n);
void func_001D1108(struct O *p, struct O *q) {
    func_001CE9B8(p, q);
    p->oid = func_0015E938(&g_sw, 4, q->oid, *q->pn);
    p->gF4 = q->gF4;
}
