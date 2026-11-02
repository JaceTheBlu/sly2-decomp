struct VTE { short d; short pad; void (*pfn)(void *, int); };
struct S { char pad[0xC]; struct VTE *vt; char pad2[0x48]; int n58; int n5C; char pad3[0x168]; int a1C8[1]; };
void PostCid71Load(struct S *p);
void func_002303A0(struct S *p, int a, int b);
void func_0017F770(struct S *p);
void func_0017F408(struct S *p, int n, void *pv);
void PostCid72Load(struct S *p) { struct VTE *e; PostCid71Load(p); e = &p->vt[0x4F]; e->pfn((char *)p + e->d, 0); func_002303A0(p, p->n58, 2); func_002303A0(p, p->n5C, 2); func_0017F770(p); func_0017F408(p, 5, p->a1C8); }
