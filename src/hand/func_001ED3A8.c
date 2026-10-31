struct AR { int cb; int cbAlign; };
void *PvAllocStackImpl__FP7SWALLOC(struct AR *par);
void *func_002333B4(void *p, int b, int cb);
extern void *D_003DD010;
extern void *D_003DD018;
extern int D_003DD00C;
extern int D_003DD014;
void func_001ED3A8(void)
{
    struct AR ar;
    void **pp1 = &D_003DD010;
    void **pp2 = &D_003DD018;
    ar.cb = 0xFFF4;
    ar.cbAlign = 0x10;
    *pp1 = PvAllocStackImpl__FP7SWALLOC(&ar);
    func_002333B4(*pp1, 0, 0xFFF4);
    ar.cb = 0xFFF4;
    ar.cbAlign = 0x10;
    *pp2 = PvAllocStackImpl__FP7SWALLOC(&ar);
    func_002333B4(*pp2, 0, 0xFFF4);
    D_003DD00C = D_003DD014 = 0;
}
