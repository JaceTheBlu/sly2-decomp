struct O { char pad[0x28]; int n; };
struct G { char pad[0x3D74]; int c; char pad2[0x854]; struct O *po; };
extern struct G g_sw;
void OnLoAdd__FP2LO(void *p);
void func_001C2078(void *p)
{
    struct G *pg;
    int c;
    OnLoAdd__FP2LO(p);
    pg = &g_sw;
    c = pg->c + 1;
    pg->c = c;
    pg->po->n = c;
}
