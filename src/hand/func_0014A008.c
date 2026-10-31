struct S { int a, b; };
struct F { int a[4]; };
struct P { char pad[0x54]; int n54; int n58; };
struct F *func_001AE478(struct F *f);
int PvAllocStackClearImpl__FP7SWALLOC(struct S *s);
void func_001A5C28(struct P *p, int a);
int PvAllocSwCopyImpl__FP7SWALLOCPv(struct S *s, int n);
void _$_18CBinaryInputStream(struct F *f, int n);
static inline void InitS(struct S *ps, int a, int b)
{
    ps->a = a * 0xC;
    ps->b = b;
}
void func_0014A008(struct P *p, int a)
{
    struct F f;
    struct S s;
    func_001AE478(&f);
    InitS(&s, 0x100, 0x10);
    p->n58 = PvAllocStackClearImpl__FP7SWALLOC(&s);
    func_001A5C28(p, a);
    InitS(&s, p->n54, 0x10);
    p->n58 = PvAllocSwCopyImpl__FP7SWALLOCPv(&s, p->n58);
    _$_18CBinaryInputStream(&f, 2);
}
