struct VTE { short d; short p; void (*pfn)(void *); };
struct VT { VTE a[3]; };
struct P { char pad[0xC]; VT *pvt; char pad2[0x24 - 0x10]; void *p24; char pad3[0x3C - 0x28]; int n3C; };
extern "C" int func_001F0638(P *);
extern "C" int IsmsFindSmRequired__FP2SM3OID(void *, int);
extern "C" void func_001F08D0(P *);
extern "C" void func_001F0D88(P *, int);
struct Lock {
    P *p;
    Lock(P *pp) { p = pp; p->pvt->a[1].pfn((char *)p + p->pvt->a[1].d); }
    ~Lock() { p->pvt->a[2].pfn((char *)p + p->pvt->a[2].d); }
};
extern "C" void func_001F0948(P *p, int n)
{
    if (!func_001F0638(p)) {
        Lock l(p);
        p->n3C = IsmsFindSmRequired__FP2SM3OID(p->p24, n);
        func_001F08D0(p);
        func_001F0D88(p, 1);
    }
}
