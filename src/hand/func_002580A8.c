typedef struct R1 { int cref; int x4; int x8; int xC[2]; int x14[1]; } R1;
typedef struct R4 { int cref; int x4; R1 *p8; } R4;
extern char D_004520D0[], D_00452148[];
void func_00257250(void *, int);
void func_00129EC8(void *);
void func_00255438(void *);
void func_00255DE8(void *);
void FreeSlotheapPv__FP8SLOTHEAPPv(void *, void *);

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

void func_002580A8(R4 **pp, R4 *p)
{
    if (p)
        p->cref++;
    Release4(*pp);
    *pp = p;
}
