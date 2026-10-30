struct O { char pad[0x28]; int n; };
struct G { char pad[0x3D74]; int c; char pad2[0x854]; struct O *po; };
extern struct G g_sw;
void func_001A5848(void *p);
void func_001C20B0(void *p)
{
    struct G *pg;
    int c;
    func_001A5848(p);
    pg = &g_sw;
    c = pg->c + 1;
    pg->c = c;
    pg->po->n = c;
}
