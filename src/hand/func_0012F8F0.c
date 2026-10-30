typedef struct S8 { int a, b; } S8;
extern S8 D_002A46C8;
extern char g_sw[];
void func_001A5C48(void *p);
void func_00149A50(void *a, void *b, S8 c, int d);
typedef struct T { char pad[0xB0]; int f; } T;
void func_0012F8F0(T *t)
{
    func_001A5C48(t);
    if (t->f)
        func_00149A50(g_sw, t, D_002A46C8, t->f);
}
