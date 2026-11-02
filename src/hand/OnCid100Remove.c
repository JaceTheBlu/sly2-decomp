struct VTE { short d; short pad; void (*pf)(void *, int); };
struct S { int a[3]; struct VTE *vt; char pad[0x158]; char y[4]; };
void OnSoRemove__FP2SO(struct S *p);
void func_001F15B8(void *d);
void OnCid100Remove(struct S *p)
{
    OnSoRemove__FP2SO(p);
    p->vt[76].pf((char *)p + p->vt[76].d, -1);
    func_001F15B8(p->y);
}
