struct S { char pad[0x110]; int x; };
void InitAlo__FP3ALO(struct S *p);
void InitCid5(struct S *p)
{
    InitAlo__FP3ALO(p);
    p->x = -1;
}
