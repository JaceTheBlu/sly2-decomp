struct VTE { short d; short pad; void (*pfn)(void *, int, int, int); };
struct O { char pad[0xC]; struct VTE *vt; };
void SetLoParent__FP2LOP2SOi(struct O *p, int a, int b) { struct VTE *e = &p->vt[10]; e->pfn((char *)p + e->d, a, 0, b); }
