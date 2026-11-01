struct S { char pad[0x40]; int fl; };
void InitLo__FP2LO(struct S *p);
void func_001A6CA8(struct S *p, int n);
void func_0020B4A8(struct S *p) {
    int v;
    InitLo__FP2LO(p);
    v = p->fl;
    if ((v ^ 1) & 1) *(int *)v |= 2; else p->fl = v | 2;
    func_001A6CA8(p, 1);
}
