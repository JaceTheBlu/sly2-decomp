struct S { char pad[0x7C]; int x7c; char pad2[0x90]; int x110; };
extern struct G g_sw;
void func_002128E8(struct S *p, int k);
void func_0020EFC0(struct G *g, int a);
void func_00213B00(struct S *p, int a);
void func_00211CA8(struct S *p, int k)
{
    if (p->x7c == -1) {
        func_002128E8(p, k);
        func_0020EFC0(&g_sw, 0);
        p->x110 = 1;
        func_00213B00(p, 0x33A);
    }
}
