typedef int qword __attribute__((mode(TI)));
typedef struct { qword r[4]; } MATRIX4;
struct S;
struct E { qword pos; float x10; long k:4; long m:8; void *child; struct S *next; };
typedef struct { short d; short pad; void *pfn; } VTE;
typedef struct { char pad[0xA4]; int xA4; } SUB;
typedef struct OBJ {
    char pad0[0xC];
    VTE *vt;
    char pad10[0x2D - 0x10];
    unsigned char x2D;
    char pad2e[0x38 - 0x2E];
    float x38;
    char pad3c[0x40 - 0x3C];
    int x40;
    char pad44[0x60 - 0x44];
    SUB *x60;
    char pad64[0x90 - 0x64];
    qword x90;
    float xA0;
    char pada4[0x140 - 0xA4];
    int x140;
    struct E *x144;
} OBJ;
extern char g_sw[];
float func_0011CAB0(MATRIX4 *);
struct E *func_001D6508(void *, qword, float, float, int);
void func_001D6378(OBJ *p)
{
    MATRIX4 m = *((MATRIX4 *(*)(void *))p->vt[31].pfn)((char *)p + p->vt[31].d);
    qword v;
    struct E *e;
    __asm__("vmulax.xyz $ACC, %1, %5x\n\tvmadday.xyz $ACC, %2, %5y\n\tvmaddaz.xyz $ACC, %3, %5z\n\tvmaddw.xyz %0, %4, $vf0w"
            : "=j"(v) : "j"(m.r[0]), "j"(m.r[1]), "j"(m.r[2]), "j"(m.r[3]), "j"(p->x90));
    {
        float r = func_0011CAB0(&m) * p->xA0;
        e = func_001D6508(g_sw, v, r, p->x38, p->x2D);
    }
    p->x144 = e;
    if (e) {
        e->k = 4;
        p->x144->child = p;
        if ((p->x40 ^ 1) & 1)
            *(int *)p->x40 |= 0x80;
        else
            p->x40 |= 0x80;
        p->x140 = p->x60->xA4;
    }
}
