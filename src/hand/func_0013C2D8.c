struct K { int a; int b; };
extern struct K D_002A4B58;
extern char g_sw[];
struct E { int f0; int f4; int f8; char pad[0x34]; };
struct S { char pad[0x184]; int st; };
void func_001F4FB0(struct S *, struct E *, int);
int func_00132B10(int, int);
void func_00149AB8(void *, void *, struct K, int);
void func_0013C2D8(struct S *p, struct E *ae, int i) {
    func_001F4FB0(p, ae, i);
    if (p->st == 5) { struct E *pe = &ae[1 - i]; if (!func_00132B10(pe->f8, 0x34)) func_00149AB8(g_sw, p, D_002A4B58, 0); }
}
