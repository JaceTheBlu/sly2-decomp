struct H { int a, b, c, d; };
struct AL { int cb; int cbAlign; int pad[2]; };
struct S { char p0[0x23C]; int x23C; void *x240; };
struct H *func_001AE478(struct H *ph);
void *PvAllocStackImpl__FP7SWALLOC(struct AL *pal);
void *PvAllocSwCopyImpl__FP7SWALLOCPv(struct AL *pal, void *pv);
void _$_18CBinaryInputStream(struct H *ph, int n);
void func_001C4EF8(struct S *p, void *pv);
void func_001C7A08(struct S *p);
void func_001C76D0(struct S *p, void *pv)
{
    struct H h;
    struct AL al;
    struct AL *pal;
    func_001AE478(&h);
    pal = &al;
    pal->cb = 0x580;
    pal->cbAlign = 0x10;
    p->x240 = PvAllocStackImpl__FP7SWALLOC(pal);
    func_001C4EF8(p, pv);
    func_001C7A08(p);
    pal->cb = p->x23C * 0x2C;
    pal->cbAlign = 0x10;
    p->x240 = PvAllocSwCopyImpl__FP7SWALLOCPv(pal, p->x240);
    _$_18CBinaryInputStream(&h, 2);
}
