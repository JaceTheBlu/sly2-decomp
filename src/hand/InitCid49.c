struct S { char pad[0x148]; unsigned long fl; };
void InitSo__FP2SO(struct S *p);
void InitCid49(struct S *p)
{
    InitSo__FP2SO(p);
    p->fl &= ~(1UL << 35);
}
