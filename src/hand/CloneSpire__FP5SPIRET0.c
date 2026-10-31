struct K { int a; int b; };
struct S { char pad[0x100]; struct K k; };
void func_002311B0(struct S *p);
void CloneSpire__FP5SPIRET0(struct S *p)
{
    struct K k = p->k;
    func_002311B0(p);
    p->k = k;
}
