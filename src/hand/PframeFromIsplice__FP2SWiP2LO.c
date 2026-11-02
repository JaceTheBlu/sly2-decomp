struct E { int a; int b; };
struct T { int a, b; struct E *ae; };
struct S { char pad[0x39E8]; struct T *pt; };
int PframeFromIsplice__FP2SWiP2LO(struct S *p, int n) { if (n == -1) return 0; return p->pt->ae[n].b; }
