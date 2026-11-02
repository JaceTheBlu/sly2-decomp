struct S { char pad[0x148]; unsigned long fl; };
void InitSo__FP2SO(struct S *p);
void func_001DE2A0(struct S *p) {
    InitSo__FP2SO(p);
    p->fl |= 0x400000000UL;
}
