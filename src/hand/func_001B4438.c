struct S { char pad[0x148]; unsigned long fl; };
void InitCid48(struct S *p);
void func_001B4438(struct S *p)
{
    InitCid48(p);
    p->fl &= ~(1UL << 35);
}
