struct K { short x; short y; int i; };
struct S { char pad[0x104]; struct K k; };
void CloneAlo__FP3ALOT0(struct S *p, int n);
void func_00156D98(struct S *p, int n)
{
    struct K k = p->k;
    CloneAlo__FP3ALOT0(p, n);
    p->k = k;
}
