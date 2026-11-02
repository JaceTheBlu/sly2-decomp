typedef int qword __attribute__((mode(TI)));
struct VTE { short d; short pad; void (*pfn)(); };
struct O { int a[3]; struct VTE *vt; };
struct P { int a; int b; float f; float g; qword q; qword r; qword s; };
void func_002333B4(void *pv, int b, int cb);
void ExplodeExpl__FP4EXPL(struct O *o)
{
    struct P p = {0};
    struct VTE *vt;

    vt = o->vt;
    vt[51].pfn((char *)o + vt[51].d, &p);
}
