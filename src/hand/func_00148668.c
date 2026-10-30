struct VTE { short d; short pad; void (*pfn)(); };
struct O { char pad[0xC]; struct VTE *vt; };
struct E { union { int oid; struct O *po; } u; int pad; };
struct L { int c; struct E ae[8]; };
extern char g_sw[];
struct O *func_0015E938(void *p, int k, int oid, void *q);
void func_00148668(struct L *l, void *q)
{
    int i;
    for (i = 0; i < l->c; i++) {
        struct O *o = func_0015E938(g_sw, 4, l->ae[i].u.oid, q);
        if (o) {
            struct VTE *e;
            l->ae[i].u.po = o;
            e = &o->vt[9];
            ((void (*)(void *))e->pfn)((char *)o + e->d);
        } else {
            l->ae[i].u.po = 0;
        }
    }
}
