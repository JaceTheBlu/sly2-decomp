struct VTE { short d; short pad; void (*pf)(void *); };
struct O { char pad[0xC]; struct VTE *vt; };
struct S { char pad[0x4C]; struct O *po; int n50; void *pv; };
void RetractAsega__FP5ASEGA(struct O *po);
void func_00143FF8(void *pv);
void func_001E5370(struct S *p)
{
    if (p->po) {
        RetractAsega__FP5ASEGA(p->po);
        { struct O *po = p->po; po->vt[2].pf((char *)po + po->vt[2].d); }
        p->po = 0;
    }
    if (p->pv) {
        func_00143FF8(p->pv);
        p->pv = 0;
    }
}
