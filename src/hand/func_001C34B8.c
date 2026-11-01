struct K { int a, b; };
struct S { char pad[0x1B4]; struct K k; };
void CloneCid10(struct S *p);
void func_001C34B8(struct S *p)
{
    struct K k = p->k;
    CloneCid10(p);
    p->k = k;
}
