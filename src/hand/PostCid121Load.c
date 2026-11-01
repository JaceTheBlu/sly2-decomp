struct K { short x; short y; int i; };
extern struct K D_002A5010;
extern char g_sw[];
void PostLoLoad__FP2LO(void *p);
void func_00149A50(void *g, void *p, struct K k, int n);
void PostCid121Load(void *p)
{
    PostLoLoad__FP2LO(p);
    func_00149A50(g_sw, p, D_002A5010, 0);
}
