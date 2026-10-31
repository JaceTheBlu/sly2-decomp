struct MSG { int cb; int nKind; };
struct G { char pad[0x45CC]; void *p45cc; };
int func_00117C80(void *pbis);
void *PvAllocSwClearImpl__FP7SWALLOC(struct MSG *pmsg);
void func_001C0F30(void *p, int n, void *pbis);
void func_001C0EC0(struct G *p, void *pbis)
{
    int n = func_00117C80(pbis);
    if (n) {
        struct MSG msg;
        msg.cb = 0x30;
        msg.nKind = 0x10;
        p->p45cc = PvAllocSwClearImpl__FP7SWALLOC(&msg);
        func_001C0F30(p->p45cc, n, pbis);
    }
}
