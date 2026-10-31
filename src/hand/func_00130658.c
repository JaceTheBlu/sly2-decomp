struct VTE { short d; short pad; void (*pfn)(); };
struct O { int pad[3]; struct VTE *vt; };
void RetractAsega__FP5ASEGA(struct O *);
void func_00130658(struct O **pp) {
    if (*pp) {
        struct O *p; struct VTE *vt;
        RetractAsega__FP5ASEGA(*pp);
        p = *pp; vt = p->vt; ((void (*)(void *))vt[2].pfn)((char *)p + vt[2].d); *pp = 0;
    }
}
