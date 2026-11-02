struct S { char pad[0x84]; int a84[3]; int n90; int n94; int n98; int n9C; };
extern char g_cm[];
void func_0014E4C8(void *a, int b, int c, void *d, int e, void *f);
void func_001E5A98(struct S *p, int n)
{
    p->n90 = n;
    p->n9C = 0;
    func_0014E4C8(g_cm, 2, 10, g_cm + 0x500, 0, p->a84);
}
