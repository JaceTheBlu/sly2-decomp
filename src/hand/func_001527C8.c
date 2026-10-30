struct K { short x; short y; int i; };
extern struct K D_002A5010;
extern char g_sw[];
void func_001A5C48(void *p);
void func_00149A50(void *g, void *p, struct K k, int n);
void func_001527C8(void *p)
{
    func_001A5C48(p);
    func_00149A50(g_sw, p, D_002A5010, 0);
}
