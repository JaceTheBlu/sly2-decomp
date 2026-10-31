struct VTE { short d; short pad; void (*pfn)(); };
typedef struct CLOCK { float t; float dt; } CLOCK;
extern CLOCK g_clock;
struct O { int a[3]; struct VTE *vt; int pad[6]; unsigned long fl; int pad2[14]; float t68; };
void func_0015E1D8(struct O *o)
{
    if (!((int)(o->fl >> 60) & 1)) {
        struct VTE *e = &o->vt[8];
        o->t68 = g_clock.t;
        e->pfn((char *)o + e->d);
    }
}
