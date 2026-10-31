typedef struct R0 { int cref; int x4; int x8[2]; int x10[1]; } R0;
typedef struct R2 { int cref; } R2;
typedef struct X { int x0; int x4; R2 *p8; int xC; int x10; R0 *p14; R0 *p18; } X;
extern char D_004520A8[], D_00452120[];
void func_00256D40(void *, int);
void func_00129EC8(void *);
void func_002550F8(void *);
void func_00255AB0(void *);
void func_00257078(void *, int);
void FreeSlotheapPv__FP8SLOTHEAPPv(void *, void *);

static inline void Release0(R0 *r)
{
    if (r) {
        if (--r->cref == 0) {
            func_00256D40(r->x10, 2);
            func_00129EC8(r->x8);
            func_002550F8(r);
            FreeSlotheapPv__FP8SLOTHEAPPv(D_004520A8, r);
        }
    }
}

void func_00257148(X *p, int flags)
{
    Release0(p->p18);
    Release0(p->p14);
    {
        R2 *r = p->p8;
        if (r) {
            if (--r->cref == 0)
                func_00257078(r, 3);
        }
    }
    func_00255AB0(p);
    if (flags & 1)
        FreeSlotheapPv__FP8SLOTHEAPPv(D_00452120, p);
}
