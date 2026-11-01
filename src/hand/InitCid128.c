struct S { char pad[0xB0]; int f; };
void InitLo__FP2LO(struct S *p);
void InitCid128(struct S *p)
{
    InitLo__FP2LO(p);
    p->f = 1;
}
