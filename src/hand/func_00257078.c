typedef struct R { int cref; char pad[8]; int xC[2]; int x14[1]; } R;
typedef struct X { char pad[0xC]; int a[4]; R *pr; } X;
extern char D_004520D0[], D_004520F8[];
void func_00257250(void *, int);
void func_00129EC8(void *);
void func_00255438(void *);
void func_00255770(void *);
void FreeSlotheapPv__FP8SLOTHEAPPv(void *, void *);
void func_002572E0(void *, int);

void func_00257078(X *p, int flags)
{
    R *r = p->pr;
    if (r) {
        if (--r->cref == 0) {
            func_00257250(r->x14, 2);
            func_00129EC8(r->xC);
            func_00255438(r);
            FreeSlotheapPv__FP8SLOTHEAPPv(D_004520D0, r);
        }
    }
    {
        int *b = p->a;
        if (b) {
            int *e = b + 4;
            while (b != e) {
                --e;
                func_002572E0(e, 0);
            }
        }
    }
    func_00255770(p);
    if (flags & 1)
        FreeSlotheapPv__FP8SLOTHEAPPv(D_004520F8, p);
}
