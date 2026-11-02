struct VTE { short d; short pad; void (*pfn)(); };
struct O { int pad[3]; struct VTE *vt; };
struct S { int f0; int f4; int f8; };
void SetLoParent__FP2LOP2SOi(struct O *, int, int);
void func_0013F990(struct O *, int);
void func_0013FA30(struct S *p, int c, struct O **apo) {
    int i;
    for (i = 0; i < c; i++) {
        struct O *po = apo[i];
        SetLoParent__FP2LOP2SOi(po, 0, 0);
        func_0013F990(po, p->f4);
        if (p->f8 != -1) ((void (*)(void *, int, int))po->vt[25].pfn)((char *)po + po->vt[25].d, p->f8, 1);
    }
}
