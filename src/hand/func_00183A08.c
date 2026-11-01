struct K { int a; int b; };
struct S { char pad[0x174]; struct K k; };
void CloneCid48(struct S *p);
void func_00183A08(struct S *p)
{
    struct K k = p->k;
    CloneCid48(p);
    p->k = k;
}
