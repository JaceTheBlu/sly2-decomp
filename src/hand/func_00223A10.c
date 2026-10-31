typedef int qword __attribute__((mode(TI)));
typedef union { qword q; float f; } U;
struct N { int a[4]; qword plane; };
void __3VUF(void *p);
float func_00223A10(void *p, qword pos, qword b, struct N *n)
{
    U d, one;
    qword plane;
    float dist;
    plane = n->plane;
    __3VUF(&d);
    __3VUF(&one);
    __asm__("vmul.xyz %1, %2, %3\n\tvaddw.x %0, $vf0, $vf0w\n\tvadday.x $ACC, %1, %1y\n\tvmaddaz.x $ACC, %0, %1z\n\tvmsubw.x %1, %0, %2w"
            : "=&j"(one.q), "=&j"(d.q) : "j"(plane), "j"(pos));
    __asm__("qmfc2.ni %0, %1" : "=r"(dist) : "j"(d.q));
    return dist;
}
