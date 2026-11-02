struct R { int cb; int cbAlign; };
struct C { int a[4]; };
struct S { char pad[0x150]; int c; void *pv; };
struct C *func_001AE478(struct C *);
void *PvAllocStackClearImpl__FP7SWALLOC(struct R *);
void LoadSoFromBrx__FP2SOP18CBinaryInputStream(struct S *, void *);
void func_0013C440(struct S *);
void *PvAllocSwCopyImpl__FP7SWALLOCPv(struct R *, void *);
void _$_18CBinaryInputStream(struct C *, int);
static inline struct R *SetReq(struct R *pr, int cb, int cbAlign) { pr->cb = cb; pr->cbAlign = cbAlign; return pr; }
void LoadCid103FromBrx(struct S *p, void *a) {
    struct C ctx;
    struct R req;
    func_001AE478(&ctx);
    p->pv = PvAllocStackClearImpl__FP7SWALLOC(SetReq(&req, 0x580, 0x10));
    LoadSoFromBrx__FP2SOP18CBinaryInputStream(p, a);
    func_0013C440(p);
    p->pv = PvAllocSwCopyImpl__FP7SWALLOCPv(SetReq(&req, p->c * 0x2c, 0x10), p->pv);
    _$_18CBinaryInputStream(&ctx, 2);
}
