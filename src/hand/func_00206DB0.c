extern int D_002C3D10[];
extern char g_sw[];
int func_0015E9C8(void *p, int a, int b, int c, int d, int e);
void func_00208920(void *p, int n);
void func_00206DB0(void *p)
{
    unsigned int i;
    for (i = 0; i < 5; i++) {
        int n = D_002C3D10[i];
        if (func_0015E9C8(g_sw, 0x605, n, 0, 0, 0))
            func_00208920(p, n);
    }
}
