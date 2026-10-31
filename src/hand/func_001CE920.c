typedef int qword __attribute__((mode(TI)));
struct M3 { qword a, b, c; };
struct RIP { char pad[0x14]; float t14; float g18; int x1c; float g20; char pad2[0xC]; qword q30; struct M3 m; qword q70; qword q80; char pad3[0x50]; int ne0; };
extern float g_clock;
extern qword D_002C1F50;
extern struct M3 D_002A2D00;
void func_001CE920(struct RIP *p, qword pos, int n, float g)
{
    /*B*/p->ne0 = n;
    p->g18 = 1.0f;
    p->t14 = g_clock;
    p->g20 = g;
    p->q30 = D_002C1F50;
    p->q80 = pos;
    p->q70 = pos;
    p->m = D_002A2D00;/*E*/
}
