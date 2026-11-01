struct S { char pad[0xF4]; int a; int b; int c; char pad2[0x10]; int d; };
void InitAlo__FP3ALO(struct S *p);
void func_00203568(struct S *p) { InitAlo__FP3ALO(p);
p->a = -1; //P
p->d = -1; //P
p->c = -1; //P
p->b = -2; //P
}
