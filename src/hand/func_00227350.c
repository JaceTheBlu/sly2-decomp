struct S { char pad[0x110]; int x; };
void InitAlo__FP3ALO(struct S *p);
void func_00227350(struct S *p)
{
    InitAlo__FP3ALO(p);
    p->x = -1;
}
