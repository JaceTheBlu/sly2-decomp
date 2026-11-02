struct S { char pad[0x58]; int n58; int n5C; char pad2[0x294 - 0x60]; int x294; };
struct O { char pad[0x264]; int oid; void *p268; char x26C[0x28]; int x294; };
void PostSoLoad(struct O *p);
int func_001E94B0(int a, int b);
void func_002303A0(struct O *p, int n, int f);
void *func_001F6030(struct O *p, int oid);
void func_00203AF0(struct O *p, void *pv);
void func_001F2AD0(struct O *p, void *pv);
void func_001EEC70(void *pv);
void PostStepLoad__FP4STEP(struct O *p)
{
    PostSoLoad(p);
    p->x294 = func_001E94B0(0x2C9, 0x10);
    func_002303A0(p, ((struct S *)p)->n58, 1);
    func_002303A0(p, ((struct S *)p)->n5C, 1);
    if (p->oid != -1) {
        p->p268 = func_001F6030(p, p->oid);
        if (p->p268) {
            func_00203AF0(p, p->p268);
            func_001F2AD0(p, p->p268);
        }
    }
    func_001EEC70(p->x26C);
}
