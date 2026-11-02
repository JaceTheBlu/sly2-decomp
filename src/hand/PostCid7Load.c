struct VTE { short d; short pad; void (*pfn)(void *); };
struct O { int a[3]; struct VTE *vt; char pad[0xF0]; int n100; };
struct G { char pad[0x4760]; int n; };
extern struct G g_sw;
void PostLoLoad__FP2LO(struct O *p);
int func_001C7BB8(int n);
void PostCid7Load(struct O *p)
{
    PostLoLoad__FP2LO(p);
    p->n100 = g_sw.n++;
    if (func_001C7BB8(p->n100)) { struct VTE *e = &p->vt[9]; e->pfn((char *)p + e->d); }
}
