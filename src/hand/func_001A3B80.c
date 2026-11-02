typedef int qword __attribute__((mode(TI)));
typedef union { qword q; float f; } U;
struct N { qword plane; struct N *x10; struct N *x14; int x18; int x1C; };
struct S { char pad[0x4564]; char *x4564; };
void __3VUF(void *p);
struct BS { int a[8]; };
static __inline__ void SetBit(int *a, int bit) { int *pw = &a[bit / 32]; *pw |= 1 << bit; }
void func_001A3B80(struct S *s, struct N *n, qword pos, float r, int bit)
{
    U d, one;
    qword plane;
    float dist;
    plane = n->plane;
    __3VUF(&d);
    __3VUF(&one);
    __asm__("vmul.xyz %1, %3, %4\n\tvaddw.x %0, $vf0, $vf0w\n\tvadday.x $ACC, %1, %1y\n\tvmaddaz.x $ACC, %0, %1z\n\tvmsubw.x %1, %0, %3w\n\tqmfc2.ni %2, %1"
            : "=&j"(one.q), "=&j"(d.q), "=r"(dist) : "j"(plane), "j"(pos));
    if (dist < r) {
        if (n->x10)
            func_001A3B80(s, n->x10, pos, r, bit);
        else
            SetBit(((struct BS *)s->x4564)[n->x18].a, bit);
    }
    if (-r < dist) {
        if (n->x14)
            func_001A3B80(s, n->x14, pos, r, bit);
        else
            SetBit(((struct BS *)s->x4564)[n->x1C].a, bit);
    }
}
