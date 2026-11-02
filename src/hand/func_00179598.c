typedef int qword __attribute__((mode(TI)));
extern qword D_002A2DD0;
struct G { int a; };
extern struct G g_sw;
struct S { char pad[0x10]; char *p10; };
void func_00174B28(struct S *p);
void func_00156C80(struct G *g, int a, qword q, int b, void *pv);
void func_00179598(struct S *p) { func_00174B28(p); func_00156C80(&g_sw, -1, D_002A2DD0, 0, p->p10 + 0x35C); }
