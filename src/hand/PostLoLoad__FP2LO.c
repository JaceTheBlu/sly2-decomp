struct VTE { short d; short pad; void *pfn; };
struct S {
    void *x0; int x4, x8; struct VTE *vt; char pad[0x18];
    long b0 : 52; long st : 4; long b1 : 8;
    float x30; char pad2[0xC]; int x40;
};
extern float D_002A6A40;
void func_001A5D98(struct S *s);
int func_00127DB8(void *p, int a, int b);
void func_001A6CA8(struct S *s, int n);
void PostLoLoad__FP2LO(struct S *s)
{
    struct VTE *e;
    func_001A5D98(s);
    e = &s->vt[3];
    ((void (*)(void *, int, int, int, int, int))e->pfn)((char *)s + e->d, 0, 1, 0, 0, 0);
    if (s->x0 && func_00127DB8(s->x0, 1, 1)) {
        int v;
        if (s->st == 2)
            func_001A6CA8(s, 0);
        v = s->x40;
        if ((v ^ 1) & 1) *(int *)v |= 2;
        else s->x40 = v | 2;
    } else {
        s->x30 = D_002A6A40;
    }
}
