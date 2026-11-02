struct Q { int a[4]; } __attribute__((aligned(16)));
struct Q3 { Q a, b, c; };
struct F { char pad[0x54]; char *p54; };
struct G { char pad[0x3BE8]; F *pf; };
extern "C" G g_sw;
struct C8 { char pad[0x9C]; float f9C; float fA0; };
struct P8 { char pad[0xA4]; int xA4; char padA8[0x20]; C8 *pC8; };
struct R { char pad[8]; P8 *p8; char padc[0x10]; int x1C; float f20; float f24; float f28; int x2C; int x30; };
struct S { int x0; int x4; char *x8; char *xC; char *x10; int x14; int x18; char pad1c[0x24]; Q q40; Q q50;
  char pad60[4]; float f64; float f68; int x6C; int x70; float f74; float f78; float f7C; float f80; float f84; float f88;
  int x8C; int x90; int x94; };
extern "C" void func_00215CA8(S *p, int i);
extern "C" S *func_00215BA8(S *p, int a, R *r, Q3 *pq)
{
    Q3 t = *pq;
    p->x0 = a;
    p->x6C = 0;
    p->x70 = 0;
    p->f74 = r->f24;
    p->f78 = r->f28;
    p->f7C = 1.0f;
    p->f80 = 1.0f;
    p->x90 = r->x2C;
    p->x8C = r->x30;
    p->f64 = r->p8->pC8->f9C;
    p->f68 = r->p8->pC8->fA0;
    p->x94 = r->p8->xA4;
    p->f84 = r->f20;
    p->f88 = p->f84 * 0.01953125f;
    p->x8 = p->xC = g_sw.pf->p54;
    p->x10 = g_sw.pf->p54 + 0x40;
    p->x18 = r->x1C;
    p->q40 = t.b;
    p->q50 = t.c;
    func_00215CA8(p, 0);
    return p;
}
