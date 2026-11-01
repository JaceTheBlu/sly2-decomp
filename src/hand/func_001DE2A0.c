struct S { char pad[0x148]; unsigned long fl; };
void InitCid48(struct S *p);
void func_001DE2A0(struct S *p) {
    InitCid48(p);
    p->fl |= 0x400000000UL;
}
