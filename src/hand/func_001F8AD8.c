typedef int qword __attribute__((mode(TI)));
struct M3 { qword a[3]; };
struct O { char pad[0xA0]; int nA0; };
struct P { char pad[0x24]; struct O *po; };
void func_0022FD38(struct M3 *, int, int);
qword DecomposeRotateMatrixEuler__FP7MATRIX3(struct M3 *);
void func_001F89E0(struct P *, int, int, qword);
void func_001F8AD8(struct P *p, int a, int b)
{
    struct M3 c, t;
    func_0022FD38(&t, 0, p->po->nA0);
    c = t;
    func_001F89E0(p, a, b, DecomposeRotateMatrixEuler__FP7MATRIX3(&c));
}
