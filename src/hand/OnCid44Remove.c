extern char g_cm[];
void OnLoRemove__FP2LO(void *p);
void func_0014E4C8(void *a, int b, int c, void *d, int e, void *f);
typedef struct T { char pad[0x124]; int f; } T;
void OnCid44Remove(T *t)
{
    OnLoRemove__FP2LO(t);
    if (t->f)
        func_0014E4C8(g_cm, 15, 10, g_cm + 0x4A8, 0, t);
}
