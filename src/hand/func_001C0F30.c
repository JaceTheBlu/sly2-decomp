typedef struct VECTOR { float x, y, z, w; } __attribute__((aligned(16))) VECTOR;
struct E { VECTOR *pv; short a; short b; };
struct S { int c0; struct E *ae; int c8; VECTOR *av; int c10; int *a14; void *x18; };
struct A { int cb; int align; };
int func_00117C80(void *pbis);
int func_00117C20(void *pbis);
void ReadVector4__18CBinaryInputStreamP7VECTOR4(void *pbis, VECTOR *pv);
int func_00117DB8(void *pbis);
void *PvAllocSwImpl__Fi(struct A *pa);
void *PvAllocSwClearImpl__FP7SWALLOC(struct A *pa);
void func_001C0F30(struct S *p, int c, void *pbis)
{
    struct A a;
    int i, j;
    p->c0 = c;
    p->c8 = func_00117C80(pbis);
    p->c10 = func_00117C80(pbis);
    a.cb = p->c0 * 8;
    a.align = 0x10;
    p->ae = PvAllocSwImpl__Fi(&a);
    a.cb = p->c8 * 16;
    a.align = 0x10;
    p->av = PvAllocSwImpl__Fi(&a);
    a.cb = p->c10 * 4;
    a.align = 0x10;
    p->x18 = PvAllocSwClearImpl__FP7SWALLOC(&a);
    a.cb = p->c10 * 4;
    a.align = 0x10;
    p->a14 = PvAllocSwImpl__Fi(&a);
    for (i = 0; i < p->c0; i++) {
        struct E *pe = &p->ae[i];
        pe->pv = &p->av[func_00117C20(pbis)];
        pe->a = func_00117C20(pbis);
        pe->b = func_00117C20(pbis);
    }
    for (j = 0; j < p->c8; j++)
        ReadVector4__18CBinaryInputStreamP7VECTOR4(pbis, &p->av[j]);
    for (j = 0; j < p->c10; j++)
        p->a14[j] = func_00117DB8(pbis);
}
