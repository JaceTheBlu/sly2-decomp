struct D { int a; int ib; };
extern char g_sw[];
int func_0015E938(void *, int, int, void *);
void func_0013E590(char *p, struct D *pd) {
    *(int *)(p + pd->ib) = func_0015E938(g_sw, 4, pd->a, p);
}
