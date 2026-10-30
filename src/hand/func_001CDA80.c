struct VTE { short d; short pad; void (*pf)(); };
struct LO { char pad[0xC]; struct VTE *vt; };
struct E { int grf; struct LO *plo; };
struct G { char pad[0x3D5C]; int x3D5C; int x3D60; int x3D64; char p1[0x3F14 - 0x3D68]; int c; int x3F18; int *pi; struct E *ae; };
extern char D_003B3980[];
extern void *D_003D4A50;
extern char D_003DA0F0[];
extern char D_002DEA00[];
extern char D_002DEA28[];
void func_001A3EE8(struct G *p);
void func_001CD9E0(struct G *p);
void func_001DAC58(void *p);
void Flush__4DMAS(void *p);
void func_001CDA80(struct G *p)
{
    int i;
    func_001A3EE8(p);
    p->x3D60++;
    D_003D4A50 = D_003B3980;
    if (p->x3D5C != p->x3D64) {
        p->x3D64 = p->x3D5C;
        func_001CD9E0(p);
    }
    p->pi = &i;
    for (i = 0; i < p->c; i++) {
        struct E *pe = &p->ae[i];
        if ((pe->grf & 0x88) == 8)
            ((void (*)(void *))pe->plo->vt[19].pf)((char *)pe->plo + pe->plo->vt[19].d);
    }
    p->pi = 0;
    func_001DAC58(D_003DA0F0);
    Flush__4DMAS(D_002DEA00);
    Flush__4DMAS(D_002DEA28);
}
