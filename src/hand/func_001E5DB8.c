struct S { char pad[0x17C]; int n; };
void CloneAlo__FP3ALOT0(struct S *p);
void func_001E7840(struct S *p, int n);
void func_001E5DB8(struct S *p)
{
    CloneAlo__FP3ALOT0(p);
    if (p->n) {
        p->n = 0;
        func_001E7840(p, 0);
    }
}
