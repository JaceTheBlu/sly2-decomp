struct VTE { short d; short pad; void (*pfn)(void *, int, void *); };
struct VT { struct VTE e[8]; };
struct S { int x0, x4, x8; struct VT *vt; char pad[0x18]; unsigned long x28; };
extern char g_sw[];
void func_001A00D0(void *g, struct S *s, int n);
void func_001A5848(struct S *s)
{
    s->x28 &= ~0x1000000000000000UL;
    if (s->x28 & 0x0800000000000000UL)
        func_001A00D0(g_sw, s, 0);
    s->vt->e[4].pfn((char *)s + s->vt->e[4].d, 1, s);
}
