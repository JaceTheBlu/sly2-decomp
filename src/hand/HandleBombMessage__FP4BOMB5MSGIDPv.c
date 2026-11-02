struct S { char pad[0x150]; int f150; };
struct M { int f0; struct S *ps; };
void func_00133590(struct S *, int, struct M *);
void func_0013B5C8(struct S *, float);
void HandleBombMessage__FP4BOMB5MSGIDPv(struct S *p, int msg, struct M *pm) {
    func_00133590(p, msg, pm);
    if (msg == 4 && pm->ps == p && p->f150 == 0) func_0013B5C8(p, 0.0f);
}
