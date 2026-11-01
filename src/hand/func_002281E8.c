struct S { char pad[0x40]; int f; char pad2[0x10C]; int a, b; };
static inline int FIsPtr(int f) { return !(f & 1); }
void InitAlo__FP3ALO(struct S *p);
void func_001A6CA8(struct S *p, int a);
void func_002281E8(struct S *p)
{
    int f;
    InitAlo__FP3ALO(p);
    p->a = 0x189;
    p->b = -1;
    func_001A6CA8(p, 0);
    f = p->f;
    if (FIsPtr(f)) *(int *)f |= 2;
    else p->f = f | 2;
}
