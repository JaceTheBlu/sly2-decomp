struct S { char pad[0x58]; int a; int b; char p2[0x178]; int x1d8; char p3[0x44]; char x220[4]; };
void PostCid71Load(struct S *p);
int func_001E94B0(int a, int b);
void func_002303A0(struct S *p, int a, int b);
void func_0017F408(struct S *p, int n, void *pv);
void PostCid73Load(struct S *p)
{
    PostCid71Load(p);
    p->x1d8 = func_001E94B0(0x2C9, 0x10);
    if (p->a) func_002303A0(p, p->a, 2);
    if (p->b) func_002303A0(p, p->b, 2);
    func_0017F408(p, 5, p->x220);
}
