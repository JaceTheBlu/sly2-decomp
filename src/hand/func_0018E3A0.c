struct K { int a; int b; };
extern struct K D_002A5F98;
extern char g_sw[];
void func_00144480(void *p);
void func_00149AB8(void *, void *, struct K, int);
void func_0018E3A0(void *p)
{
    func_00144480(p);
    func_00149AB8(g_sw, p, D_002A5F98, 0);
}
