struct SAAF { char pad[0xC]; float g0; float g1; float g2; float g3; int n1C; };
struct EYES { char pad[0x50]; float g0; float g1; float g2; float g3; int n60; int n64; };
void InitSaa__FP7SHUFFLEP4SAAF(struct EYES *p, struct SAAF *psaaf);
void func_001EE100(struct EYES *p, int eyess);
void func_001EE090(struct EYES *p, struct SAAF *psaaf)
{
    InitSaa__FP7SHUFFLEP4SAAF(p, psaaf);
    p->n60=psaaf->n1C;
    p->g0=psaaf->g0;
    { float a=psaaf->g1; float b=psaaf->g2; p->g1=a; p->g2=b; }
    p->g3=psaaf->g3;
    p->n64=-1;
    func_001EE100(p,0);
}
