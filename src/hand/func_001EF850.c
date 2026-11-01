struct S { char pad[0x40]; int f40; char pad2[0x148 - 0x44]; unsigned long grf; };
void PostCid48Load(struct S *p);
void func_001A6CA8(struct S *p, int n);
void func_001EF850(struct S *p)
{
    int x;
    PostCid48Load(p);
    func_001A6CA8(p, 1);
    x = p->f40;
    if ((x ^ 1) & 1) *(int *)x |= 2;
    else p->f40 = x | 2;
    p->grf &= ~(1UL << 35);
}
