struct S { char pad[0x120]; int a; char pad2[0x2c]; int b; };
void InitLo__FP2LO(struct S *p);
void func_001C2048(struct S *p) { InitLo__FP2LO(p); p->a = -1; p->b = -1; }
