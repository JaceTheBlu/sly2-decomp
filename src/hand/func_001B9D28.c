typedef int qword __attribute__((mode(TI)));
struct VTE { short d; short pad; void (*pfn)(); };
struct O { int pad[3]; struct VTE *vt; int pad1[6]; unsigned long f28; };
struct P { char pad[0x1AD0]; struct O *po; int n1AD4; };
int func_001DAEA8(int n);
void ApplyAseg__FP4ASEGP3ALOffiPP5ASEGA(int n, struct O *po, int a, int b, float g0, float g1);
void func_001B9D28(struct P *p, qword q)
{
    if (func_001DAEA8(0x11)) {
        struct O *po = p->po;
        if (!((po->f28 >> 60) & 1)) {
            struct VTE *e = &po->vt[29];
            ((void (*)(void *, qword))e->pfn)((char *)po + e->d, q);
            ApplyAseg__FP4ASEGP3ALOffiPP5ASEGA(p->n1AD4, p->po, 0, 0, 0.0f, 1.0f);
        }
    }
}
