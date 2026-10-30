typedef int qword __attribute__((mode(TI)));
typedef struct VTE { short d; short pad; void (*pfn)(); } VTE;
typedef struct I { int a; int b; } I;
typedef struct E { int id; int n; int c; void *a; } E;
typedef struct P {
    char pad0[0xC];
    VTE *vt;
    char pad10[0x150 - 0x10];
    int c150;
    I *x154;
    int x158;
    int i;
    int c;
    E *ae;
    int x168;
    void *x16C;
    int x170;
} P;
extern char g_sw[];
extern char D_002DEB30[];
int func_001BBE48(P *p);
int func_001BBE18(P *p);
void *func_001C4840(void *g);
int func_00132B10(void *p, int k);
void func_001BB648(P *p, E *pe);
qword func_001A62E8(P *p);
void func_00156B98(void *g, int z, qword q, void *x);
void func_001619A0(void *g, int k, P *p);

void func_001BB400(P *p)
{
    E *pe;
    int v;
    if (func_001BBE48(p)) return;
    if (p->x16C == func_001C4840(g_sw)) {
        p->x168 = 0xE;
    } else {
        v = p->x170;
        if (v == 0x100 || v == 0x10000 || v == 0x20000 || (p->x16C && func_00132B10(p->x16C, 0x3B)))
            p->x168 = 8;
        else
            p->x168 = 0;
    }
    ((void (*)(void *, int, int, int, int, int))p->vt[3].pfn)((char *)p + p->vt[3].d, 0x10, 0, 0, 0, 0);
    if (p->x168 & 1) return;
    pe = &p->ae[p->i];
    func_001BB648(p, p->ae - 1);
    func_001BB648(p, pe);
    if (!p->x16C || !func_00132B10(p->x16C, 0x38) || func_00132B10(p->x16C, 0x3C)) {
        func_00156B98(g_sw, 0, func_001A62E8(p), p->x16C);
    }
    if (pe->n > 0) {
        if (++p->x158 >= pe->n) {
            p->x158 = 0;
            if (++p->i >= p->c) {
                ((void (*)(void *, int, P *))p->vt[4].pfn)((char *)p + p->vt[4].d, 0x10, p);
                ((void (*)(void *, int, int, int, int, int))p->vt[3].pfn)((char *)p + p->vt[3].d, 5, 0, 0, 0, 0);
                func_001619A0(D_002DEB30, 0x11, p);
            }
        }
    }
    if (func_001BBE18(p)) {
        pe = &p->ae[p->i];
        if (pe->n <= 0) {
            int i;
            for (i = 0; i < p->c150; i++) p->x154[i].b = 0;
        }
    }
}
