struct K { int a, b; };
struct S { char pad[0x104]; struct K k; };
void CloneAlo__FP3ALOT0(struct S *);
void func_001FF4A8(struct S *p) { struct K k = p->k; CloneAlo__FP3ALOT0(p); p->k = k; }
