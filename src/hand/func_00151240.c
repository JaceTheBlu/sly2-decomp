typedef int qword __attribute__((mode(TI)));
extern qword D_002A2DD0;
extern char g_cm[];
struct A { int n0; int pad[3]; void *pb; int n14; float g18; };
void func_0014FCC8(struct A *a, int n, void *b);
void SetCmNearClip__FP2CMf(void *pg, float g);
void func_0014F5A0(void *pg, float g);
int func_0012DC18(int n, void *pb, int a, int b, int c, qword q);
void func_00151240(struct A *a, int n, void *b)
{
    void *pg;
    func_0014FCC8(a, n, b);
    a->pb = b;
    pg = g_cm;
    SetCmNearClip__FP2CMf(pg, 25.0f);
    func_0014F5A0(pg, 1.15f);
    a->n14 = func_0012DC18(a->n0, a->pb, 1, 8, 3, D_002A2DD0);
    a->g18 = -1.0f;
}
