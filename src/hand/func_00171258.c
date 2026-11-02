struct S;
struct VTE { short d; short pad; void (*pfn)(); };
struct T { int n0; char pad[0x4C]; int n50; };
struct U { int n0; int n4; };
struct S { int pad0; char a4[8]; struct VTE *vt; char pad[8]; char a18[0x18]; struct T *pt; int n34; int n38; int pad3; int n40; struct U *pu; int pad4; int n4C; };
void func_001EF0D8(void *p);
void __as__3SPXP1X(struct S *p, int n);
void func_002580A8(void *p, int n);
void func_00171258(struct S *p, struct T *t, int a, struct U *u) {
    if (t == p->pt) return;
    if (p->pt) {
        func_001EF0D8(p->a18);
        p->vt[3].pfn((char *)p + p->vt[3].d, 3, 0, 0, 0, 0);
        __as__3SPXP1X(p, 0);
        func_002580A8(p->a4, 0);
        p->n34 = 0;
        p->n38 = 0;
        p->n40 = 0;
        p->n4C = 0;
    }
    p->pt = t;
    if (!t) return;
    __as__3SPXP1X(p, t->n0);
    p->vt[3].pfn((char *)p + p->vt[3].d, 2, 0, 0, 0, 0);
    p->n4C = a;
    if (!u || !u->n0) {
        struct T *x = p->pt;
        int n = x->n50;
        p->n34 = (int)x;
        p->n38 = n;
    } else {
        p->n38 = u->n0;
        p->pu = u;
        p->n34 = u->n4;
    }
    if (p->n38) p->vt[15].pfn((char *)p + p->vt[15].d, p->n38);
    p->pu = 0;
}
