struct S { char pad[0x4A4]; int f; };
void InitStepguard__FP9STEPGUARD(struct S *p);
void InitCid61(struct S *p) { InitStepguard__FP9STEPGUARD(p); p->f = 1; }
