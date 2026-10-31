struct G;
extern struct G g_sw;
struct O { char pad[0xF38]; void *p; };
void func_00133590(void *p, int msg, void *pm);
struct O *func_001C4840(struct G *pg);
int FIsBasicDerivedFrom__FP5BASIC3CID(void *o, int n);
void func_00202030(void *p);
void func_002021F8(void *p);
void func_00203670(void *p, int msg, void *pm)
{
    struct O *o;
    func_00133590(p, msg, pm);
    if (msg != 0x11) return;
    o = func_001C4840(&g_sw);
    if (o && FIsBasicDerivedFrom__FP5BASIC3CID(o, 0x34) && o->p) {
        func_00202030(o->p);
        func_002021F8(o->p);
    }
}
