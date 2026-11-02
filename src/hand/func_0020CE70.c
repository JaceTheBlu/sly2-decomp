struct VE { short d; short pad; int (*pf)(void *, int); };
struct O { char pad[0xC]; struct VE *vt; };
struct S { struct O *po; int k; float t; int n; };
extern struct { float t; float dt; } g_clock;
extern float D_002C3DF0;
int func_0020D020(struct S *p);
void func_0020D108(struct S *p, int k);

void func_0020CE70(struct S *p)
{
    int f, k;
    if (!p->n)
        return;
    f = func_0020D020(p);
    do {
        k = p->k;
        switch (k) {
        case 0:
            if (f)
                func_0020D108(p, 1);
            break;
        case 1:
            if (!f)
                func_0020D108(p, 0);
            else if (g_clock.t - p->t > D_002C3DF0 && !p->po->vt[76].pf((char *)p->po + p->po->vt[76].d, 0x4000))
                func_0020D108(p, 2);
            break;
        case 2:
            if (!f)
                func_0020D108(p, 0);
            break;
        }
    } while (p->k != k);
}
