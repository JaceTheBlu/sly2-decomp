struct S { char p0[0x40]; int x40; char p1[0x150-0x44]; int n150; int a[2]; int n15C; };
void InitSo__FP2SO(struct S *p);
void InitCid108(struct S *p) {
    int v;
    InitSo__FP2SO(p);
    p->n15C = 0x1E;
    p->n150 = -1;
    v = p->x40;
    if ((v ^ 1) & 1) *(int *)v |= 2;
    else p->x40 = v | 2;
}
