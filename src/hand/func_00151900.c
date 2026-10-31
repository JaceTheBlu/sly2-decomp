struct G { char pad[0x24]; float g24; };
extern struct G g_cm;
struct B { char pad[0x1BC]; float g; };
void func_0014FCC8(void *a, struct B *b);
void SetCmNearClip__FP2CMf(struct G *pg, float g);
void func_00151900(void *a, struct B *b)
{
    struct G *pg;
    func_0014FCC8(a, b);
    pg = &g_cm;
    SetCmNearClip__FP2CMf(pg, 49.0f);
    pg->g24 = b->g;
}
