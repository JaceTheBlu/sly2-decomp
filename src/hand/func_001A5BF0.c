struct S { char pad[0x10]; struct S *x10; };
int FIsBasicDerivedFrom__FP5BASIC3CID(struct S *p, int n);
struct S *func_001A5BF0(struct S *p) { if (FIsBasicDerivedFrom__FP5BASIC3CID(p, 0x30)) return p; return p->x10; }
