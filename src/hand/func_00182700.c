struct E { int a; int b; int x8; int xc; char pad[0x30]; };
struct S { char pad[0x188]; int n; };
void InitMurray__FP6MURRAY(struct S *p, struct E *ae, int i);
int FIsBasicDerivedFrom__FP5BASIC3CID(int oid, int n);
void func_0017F5B0(struct S *p, int n);
void func_00182700(struct S *p, struct E *ae, int i)
{
    InitMurray__FP6MURRAY(p, ae, i);
    if (p->n) {
        struct E *pe = &ae[1 - i];
        int oid = pe->xc;
        if (FIsBasicDerivedFrom__FP5BASIC3CID(oid, 0x47))
            func_0017F5B0(p, oid);
    }
}
