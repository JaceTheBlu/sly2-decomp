struct A { int pad[4]; int n10; int n14; float g18; char pad2[0x40 - 0x1C]; int n40; char pad3[0xC0 - 0x44]; void *pC0; void *pC4; };
extern char g_cm[];
void func_001FB098(void *p, float g);
void func_00258040(void **pp, int n);
void func_0014D8C0(void *p);
void func_0014FCE8(struct A *a, int n, void *b);
static inline void Release(void **pp, float g)
{
    if (pp && *pp) {
        func_001FB098(*pp, g);
        func_00258040(pp, 0);
    }
}
void func_00151130(struct A *a, int n, void *b)
{
    Release(&a->pC0, 0.0f);
    Release(&a->pC4, 0.5f);
    a->n10 = 0;
    a->n14 = 0;
    a->n40 = 0;
    a->g18 = -1.0f;
    func_0014D8C0(g_cm);
    func_0014FCE8(a, n, b);
}
