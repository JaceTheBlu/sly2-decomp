typedef struct { short d; short pad; void *pfn; } VTE;
struct O { char pad[0xC]; VTE *vt; };
struct S { int k; int pad; struct O *po; };
void RetractAsega__FP5ASEGA(struct O *po);
void RetractSma__FP3SMA(struct O *po);
void func_0020C080(struct O *po);
void func_0020CA48(struct O *po);
#define VDEL(o) ((void (*)(void *))(o)->vt[2].pfn)((char *)(o) + (o)->vt[2].d)
void func_00209360(struct S *p)
{
    switch (p->k) {
    case -1:
        break;
    case 0:
        if (p->po) {
            RetractAsega__FP5ASEGA(p->po);
            VDEL(p->po);
            p->po = 0;
        }
        break;
    case 1:
        if (p->po) {
            RetractSma__FP3SMA(p->po);
            VDEL(p->po);
            p->po = 0;
        }
        break;
    case 2:
        if (p->po) {
            func_0020C080(p->po);
            VDEL(p->po);
            p->po = 0;
        }
        break;
    case 3:
        if (p->po) {
            func_0020CA48(p->po);
            VDEL(p->po);
            p->po = 0;
        }
        break;
    }
}
