struct T { char pad[0x28]; int n28; };
struct G { char pad[0x45CC]; struct T *p45CC; };
extern struct G g_sw;
struct S { char pad[0x30]; int n30; int pad2; int n38; char pad3[0x64]; float gA0; int nA4; };
void func_001EEF68(struct S *p);
void func_0017D360(struct S *p) { func_001EEF68(p); p->n30 = -1; p->n38 = -1; p->gA0 = -3.40282346638528859812e+38f; p->nA4 = g_sw.p45CC->n28; }
