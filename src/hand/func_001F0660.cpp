struct VTE { short d; short p; void (*pfn)(void *); };
struct VT { VTE a[3]; };
struct F { int pad[3]; int fl; };
struct P { char pad[0xC]; VT *pvt; char pad2[0x24 - 0x10]; void *p24; char pad3[0x30 - 0x28]; void *p30; char pad4[0x3C - 0x34]; int n3C; F *pf; };
extern "C" int func_001F0638(P *);
extern "C" int IsmsFindSmRequired__FP2SM3OID(void *, int);
extern "C" void func_00130B18(void *);
extern "C" void func_001F0D88(P *, int);
struct Lock {
    P *p;
    Lock(P *pp) { p = pp; p->pvt->a[1].pfn((char *)p + p->pvt->a[1].d); }
    ~Lock() { p->pvt->a[2].pfn((char *)p + p->pvt->a[2].d); }
};
extern "C" void func_001F0660(P *p, int n)
{
    if (func_001F0638(p)) return;
    n = n == -1 ? -1 : IsmsFindSmRequired__FP2SM3OID(p->p24, n);
    if (n != p->n3C) {
        Lock l(p);
        p->n3C = n;
        if (p->p30) {
            if (p->pf->fl & 2) func_00130B18(p->p30);
        } else func_001F0D88(p, 0);
    }
}
