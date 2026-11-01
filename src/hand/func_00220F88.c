struct K { int a, b; };
extern struct K D_002A96E8;
extern char g_sw[];
void OnLoRemove__FP2LO(void *p);
void func_00149B58(void *g, int a, void *p, struct K k, int z);
void func_00220F88(void *p)
{
    OnLoRemove__FP2LO(p);
    func_00149B58(g_sw, 1, p, D_002A96E8, 0);
}
