extern char g_cm[];
void PostLoLoad__FP2LO(void *p);
void func_0014E328(void *a, int b, void *c, int d, void *e);
typedef struct T { char pad[0x28]; unsigned long fl; char pad2[0x124 - 0x30]; int f; } T;
void PostCid44Load(T *t)
{
    PostLoLoad__FP2LO(t);
    t->f = 1;
    if ((int)(t->fl >> 60) & 1)
        func_0014E328(g_cm, 10, g_cm + 0x4A8, 0, t);
}
