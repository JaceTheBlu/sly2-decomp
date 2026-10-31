typedef struct R1 { int cref; int x4; int x8; int xC[2]; int x14[1]; } R1;
typedef struct R2 { int cref; } R2;
typedef struct R4 { int cref; int x4; R1 *p8; } R4;
extern char D_004520D0[], D_00452148[];
void func_00257250(void *, int);
void func_00129EC8(void *);
void func_00255438(void *);
void func_00255DE8(void *);
void FreeSlotheapPv__FP8SLOTHEAPPv(void *, void *);
void func_00257078(void *, int);
void func_001AE520(void *);

static inline void Release1(R1 *r)
{
    if (r) {
        if (--r->cref == 0) {
            func_00257250(r->x14, 2);
            func_00129EC8(r->xC);
            func_00255438(r);
            FreeSlotheapPv__FP8SLOTHEAPPv(D_004520D0, r);
        }
    }
}

static inline void Release4(R4 *r)
{
    if (r) {
        if (--r->cref == 0) {
            Release1(r->p8);
            func_00255DE8(r);
            FreeSlotheapPv__FP8SLOTHEAPPv(D_00452148, r);
        }
    }
}

typedef struct S { R2 *p0; R4 *p4; } S;

void func_00258348(S *p, int flags)
{
    Release4(p->p4);
    {
        R2 *r = p->p0;
        if (r) {
            if (--r->cref == 0)
                func_00257078(r, 3);
        }
    }
    if (flags & 1)
        func_001AE520(p);
}
