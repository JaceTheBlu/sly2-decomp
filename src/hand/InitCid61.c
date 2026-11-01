struct S { char pad[0x4A4]; int f; };
void InitCid56(struct S *p);
void InitCid61(struct S *p) { InitCid56(p); p->f = 1; }
