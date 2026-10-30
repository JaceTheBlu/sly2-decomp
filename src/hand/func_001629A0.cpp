class OBase {
public:
    int a, b, c;
    virtual void V1();
    virtual void V2();
    virtual void Msg(int msgid, int a, int c, void **apv, int d);
};
class O : public OBase {
public:
    char pad[0x7C - 0x10];
    int f7c;
    int pad80, pad84, pad88;
    int f8c, f90, f94, f98;
    char pad2[0xF0 - 0x9C];
    int ff0;
};
struct G;
extern G g_sw;
extern char D_002DEB30[];
extern "C" void func_00165DC0(G *pg, O *p);
extern "C" int func_00162670(O *p);
extern "C" void func_00163460(O *p);
extern "C" void func_001619A0(void *pv, int n, O *p);
extern "C" void func_001620B0(O *p, int n, int c, int a);
extern "C" void func_001623D0(O *p, int n, int c, int a, int b);
extern "C" void func_001629A0(O *p)
{
    func_00165DC0(&g_sw, p);
    if (func_00162670(p)) {
        p->f7c++;
        func_00163460(p);
        func_001619A0(D_002DEB30, 0x21, p);
        func_001620B0(p, 4, p->f8c, p->f90);
        func_001623D0(p, 4, p->f94, p->f98, p->ff0);
        p->Msg(0x13, 0, 0, 0, 0);
    }
}
