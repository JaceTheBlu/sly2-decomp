struct R { int cb; int cbAlign; };
struct C { int a[4]; };
struct S { char pad[0x150]; int c; void *pv; };
struct C *func_001AE478(struct C *);
void *func_001AE378(struct R *);
void func_001F31E0(struct S *, void *);
void func_0013C440(struct S *);
void *func_001AE238(struct R *, void *);
void _$_18CBinaryInputStream(struct C *, int);
static inline struct R *SetReq(struct R *pr, int cb, int cbAlign) { pr->cb = cb; pr->cbAlign = cbAlign; return pr; }
void func_0013BE58(struct S *p, void *a) {
    struct C ctx;
    struct R req;
    func_001AE478(&ctx);
    p->pv = func_001AE378(SetReq(&req, 0x580, 0x10));
    func_001F31E0(p, a);
    func_0013C440(p);
    p->pv = func_001AE238(SetReq(&req, p->c * 0x2c, 0x10), p->pv);
    _$_18CBinaryInputStream(&ctx, 2);
}
