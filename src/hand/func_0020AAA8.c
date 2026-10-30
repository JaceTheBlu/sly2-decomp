extern char g_sw[];
struct S { char pad[0xEB8]; int a[8]; int n; int b[8]; int c; };
int func_0015E938(void *p, int k, int x, struct S *ps);
void func_0020AAA8(struct S *p)
{
    int i;
    p->c = 0;
    for (i = 0; i < p->n; i++) {
        int r = func_0015E938(g_sw, 4, p->a[i], p);
        if (r)
            p->b[p->c++] = r;
    }
}
