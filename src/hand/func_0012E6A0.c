extern char g_cm[];
void OnLoAdd__FP2LO(void *p);
void func_0014E328(void *a, int b, void *c, int d, void *e);
typedef struct T { char pad[0x124]; int f; } T;
void func_0012E6A0(T *t)
{
    OnLoAdd__FP2LO(t);
    if (t->f)
        func_0014E328(g_cm, 10, g_cm + 0x4A8, 0, t);
}
