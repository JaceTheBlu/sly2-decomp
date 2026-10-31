struct MSG { int cb; int nKind; };
struct X { int a; int b; int c; };
struct V { int a[4]; };
struct S { char pad[0xE0]; int cv; struct V *av; int cx; struct X *ax1; struct X *ax2; };
void func_00231768(struct S *p, void *pbis);
int func_00117D50(void *pbis);
void ReadVector__18CBinaryInputStreamP6VECTOR(void *pbis, void *pv);
void *PvAllocSwImpl__Fi(struct MSG *pmsg);
void func_0013F810(struct S *p, void *pbis);
static __inline__ void *PvAllocMsg(struct MSG *pmsg, int cb, int nKind) { pmsg->nKind = nKind; pmsg->cb = cb; return PvAllocSwImpl__Fi(pmsg); }
void func_00185150(struct S *p, void *pbis)
{
    struct MSG msg;
    int i, j;
    int n;
    func_00231768(p, pbis);
    p->cv = func_00117D50(pbis);
    p->av = (struct V *)PvAllocMsg(&msg, p->cv << 4, 0x10);
    for (i = 0; i < p->cv; i++)
        ReadVector__18CBinaryInputStreamP6VECTOR(pbis, &p->av[i]);
    p->cx = func_00117D50(pbis);
    p->ax1 = (struct X *)PvAllocMsg(&msg, p->cx * 12, 0x10);
    for (j = 0; j < p->cx; j++) {
        struct X *px = &p->ax1[j];
        px->a = func_00117D50(pbis);
        px->b = func_00117D50(pbis);
        px->c = func_00117D50(pbis);
    }
    p->ax2 = (struct X *)PvAllocMsg(&msg, p->cx * 12, 0x10);
    for (j = 0; j < p->cx; j++) {
        p->ax2[j].a = func_00117D50(pbis);
        p->ax2[j].b = func_00117D50(pbis);
        p->ax2[j].c = func_00117D50(pbis);
    }
    func_0013F810(p, pbis);
}
