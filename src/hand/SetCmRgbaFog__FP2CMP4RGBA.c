struct S4 { char a[4]; };
struct CM { char pad[0x24C]; struct S4 s; };
void func_001ED278(void *p);
void RecalcCmFrustrum__FP2CM(struct CM *p);
void SetCmRgbaFog__FP2CMP4RGBA(struct CM *p, struct S4 *s)
{
    p->s = *s;
    func_001ED278(&p->s);
    RecalcCmFrustrum__FP2CM(p);
}
