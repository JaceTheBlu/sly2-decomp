typedef int qword __attribute__((mode(TI)));
struct S { qword a[5]; };
struct VTE { short d; short pad; void (*pfn)(void *, struct S *); };
struct O { int pad[3]; struct VTE *vt; };
struct P { char pad[0x260]; struct O *po; int pad2[3]; struct S s; };
qword CalcCmAdjust__FP2CMP2SOP6CPDEFIP6VECTOR(struct P *p, struct S *ps);
void func_0014E968(struct P *p, struct O *po, struct S *ps)
{
    if (po == p->po) {
        *ps = p->s;
    } else {
        struct VTE *e = &po->vt[50];
        qword q, r;
        e->pfn((char *)po + e->d, ps);
        q = CalcCmAdjust__FP2CMP2SOP6CPDEFIP6VECTOR(p, ps);
        __asm__("vadd.xyzw %0, %1, %2" : "=j"(r) : "j"(ps->a[1]), "j"(q));
        ps->a[4] = r;
    }
}
