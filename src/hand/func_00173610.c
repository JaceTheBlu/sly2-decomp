typedef int qword __attribute__((mode(TI)));
typedef union { qword q; float f; } U;
struct G;
extern struct G g_sw;
extern qword g_normalZ;
struct X { int a[4]; };
struct Y { qword v; char pad[0x18]; float f28; char pad2[0x14]; float f40; char pad3[0x1C]; };
struct X *func_001AE478(struct X *x);
void _$_18CBinaryInputStream(struct X *x, int n);
int func_0020FA50(void);
void func_0020FAA0(struct G *g, qword a, qword b, int (*fn)(void), int z, int *pa, int *pb);
int func_0014CC58(int n, qword a, qword b, int c, int d, struct Y *y);
static __inline__ qword MAdd(qword p, qword up, float s) {
    U u;
    qword r;
    __asm__("qmtc2.ni %1, %0" : "=j"(u.q) : "r"(s));
    __asm__("vadda.xyzw $ACC, %1, $vf0\n\tvmaddx.xyzw %0, %2, %3x" : "=j"(r) : "j"(p), "j"(up), "j"(u.q));
    return r;
}
int func_00173610(qword *pv, float a, float b, int k, int (*fn)(void)) {
    struct X x;
    int na, nb;
    qword va, vb;
    func_001AE478(&x);
    va = MAdd(*pv, g_normalZ, a);
    vb = MAdd(*pv, g_normalZ, b);
    if (!fn) fn = func_0020FA50;
    {
    struct Y y;
    func_0020FAA0(&g_sw, va, vb, fn, 0, &na, &nb);
    if (!func_0014CC58(1, va, vb, na, nb, &y) || y.f40 == 0.0f || (!k && y.f28 < 0.7f)) {
        _$_18CBinaryInputStream(&x, 2);
        return 0;
    }
    *pv = y.v;
    }
    _$_18CBinaryInputStream(&x, 2);
    return 1;
}
