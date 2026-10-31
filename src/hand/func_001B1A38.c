typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V;
struct VE { short d; short pad; void (*pfn)(); };
struct C { struct VE *vt; };
struct Y { int x0; struct C *pc; };
struct X { char pad[0x74]; float f74; float f78; };
struct Y *PchnFindAseg__FP4ASEGP3ALOii(struct X *px, void *p, int a, int b);
void func_001B1A38(void *p, struct X *px, float *pf)
{
    V v0, v1;
    struct Y *py;
    struct C *pc;
    if (!px) return;
    py = PchnFindAseg__FP4ASEGP3ALOii(px, p, 1, 1);
    if (!py) return;
    pc = py->pc;
    ((void (*)(void *, V *, int, float, float))pc->vt[3].pfn)((char *)pc + pc->vt[3].d, &v0, 0, 0.0f, 1.0f);
    pc = py->pc;
    ((void (*)(void *, V *, int, float, float))pc->vt[3].pfn)((char *)pc + pc->vt[3].d, &v1, 0, px->f74, 1.0f);
    *pf = __builtin_fabsf(v1.x - v0.x) / px->f74 * px->f78;
}
