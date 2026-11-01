struct Q { char b[8]; };
struct S { char pad[0xE0]; struct Q q; };
void CloneAlo__FP3ALOT0(struct S *p);
void func_0021D390(struct S *p)
{
    struct Q t = p->q;
    CloneAlo__FP3ALOT0(p);
    p->q = t;
}
