struct S { char pad[0x168]; void *p168; int a16c; };
extern char D_002C0CB0[];
void PostCid48Load(struct S *p);
void func_001A64E8(struct S *p, int n, void *q);
void func_001F1448(void *a, struct S *p, int b, int c, int *pn);
void func_001C2D20(struct S *p)
{
    PostCid48Load(p);
    func_001A64E8(p, 4, D_002C0CB0);
    func_001F1448(p->p168, p, -1, 0, &p->a16c);
}
