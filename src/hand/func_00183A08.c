struct K { int a; int b; };
struct S { char pad[0x174]; struct K k; };
void CloneSo__FP2SOT0(struct S *p);
void func_00183A08(struct S *p)
{
    struct K k = p->k;
    CloneSo__FP2SOT0(p);
    p->k = k;
}
