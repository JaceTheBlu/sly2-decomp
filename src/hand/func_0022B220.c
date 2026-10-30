struct CHK { int a[16]; };
struct X { int flags; struct CHK chk; int a; int b; };
struct M { char pad[0x3C40]; struct CHK chk; };
extern struct M g_sw;
extern struct CHK D_003E10D0;
struct S { int k; int x4; struct X x; void *po; int n; };
void func_0022B090(struct S *p, int k);
void func_0020DF80(struct M *pm, struct X *px);
void *func_0015E938(struct M *pm, int k, int n, int z);
static __inline__ int FSameChk(struct CHK *a, struct CHK *b)
{
    if (a == b) return 1;
    if (!a || !b) return 0;
    return (a->a[2] ^ a->a[14]) == (b->a[2] ^ b->a[14]);
}
void func_0022B220(struct S *p, struct X *px, int n, int f)
{
    switch (p->k) {
    case 0:
        break;
    case 1:
        return;
    case 2:
        func_0022B090(p, 0);
        break;
    case 3:
        return;
    }
    if (FSameChk(&D_003E10D0, &px->chk))
        px->flags |= 2;
    else
        px->flags &= ~2;
    p->po = func_0015E938(&g_sw, 0x405, n, 0);
    if (!p->po) {
        func_0020DF80(&g_sw, px);
        return;
    }
    p->x4 = 1;
    p->x = *px;
    p->n = n;
    func_0022B090(p, f);
}
