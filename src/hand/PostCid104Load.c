struct VTE { short d; short pad; void (*pfn)(); };
struct O { char pad[0xC]; struct VTE *vt; char pad2[0x150 - 0x10]; int n150; };
extern char D_002BD380[];
void PostSoLoad(void *p);
void func_001A64E8(void *p, int n, void *q);
void PostCid104Load(struct O *p)
{
    struct VTE *e;
    PostSoLoad(p);
    func_001A64E8(p, 2, D_002BD380);
    e = &p->vt[9];
    p->n150 = -1;
    ((void (*)(void *))e->pfn)((char *)p + e->d);
}
