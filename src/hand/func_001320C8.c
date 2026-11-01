struct S { char pad[0x148]; unsigned long grf; };
void InitCid48(struct S *);
void func_001320C8(struct S *p) { InitCid48(p); p->grf |= 0x8000L << 19; }
