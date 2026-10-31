struct B { int a[12]; };
struct MK { int a; };
extern int D_003DCF9C, D_003DCF98;
extern int D_002DE598;
void __4GIFS(struct B *pb);
struct MK *func_001AE478(struct MK *pm);
void _$_18CBinaryInputStream(struct MK *pm, int n);
void func_001572E0(struct B *pb, int n);
void func_001574B8(struct B *pb);
int func_001ECC28(int a, void *p, struct B *pb);
void func_00166BD8(struct B *pb, int a, int b, int c);
void func_00166E90(struct B *pb, int a, int b);
void func_00166968(struct B *pb);
void func_001576B0(struct B *pb);
void func_00157348(struct B *pb, int a, int *pn);
void func_0016F8B8(int a, int b);
void func_00170730(void *p) {
    struct B b;
    struct MK mk;
    int n;
    __4GIFS(&b);
    func_001AE478(&mk);
    func_001572E0(&b, ((D_003DCF9C * 3 + D_003DCF98) << 3) | 4);
    func_001574B8(&b);
    if (func_001ECC28(1, p, &b)) {
        func_00166BD8(&b, 0, 1, 0xE);
        func_00166E90(&b, 0x3F, 0);
        func_00166E90(&b, 0x61, 0);
        func_00166968(&b);
        func_001576B0(&b);
        func_00157348(&b, 0, &n);
        func_0016F8B8(D_002DE598, n);
    }
    _$_18CBinaryInputStream(&mk, 2);
}
