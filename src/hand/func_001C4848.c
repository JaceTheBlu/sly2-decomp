struct MSG { int cb; int nKind; };
struct V { int a, b; void *p8; };
struct G { char pad[0x4778]; unsigned int c; void *a[4]; };
struct V *func_00258658(void *p, int n);
void *PvAllocSwClearImpl__FP7SWALLOC(struct MSG *pmsg);
void func_001C4848(struct G *p, void *q)
{
    if (p->c < 4) {
        struct V *pv;
        p->a[p->c++] = q;
        pv = func_00258658(q, 1);
        if (!pv->p8) {
            struct MSG msg;
            msg.cb = 0x14;
            msg.nKind = 0x10;
            pv->p8 = PvAllocSwClearImpl__FP7SWALLOC(&msg);
        }
    }
}
