struct S { char pad[0x38]; float g; };
extern float D_002C3C58;
void PostLoLoad__FP2LO(struct S *);
void func_001FF3E8(struct S *p) { PostLoLoad__FP2LO(p); if (p->g == 1e10f) p->g = D_002C3C58; }
