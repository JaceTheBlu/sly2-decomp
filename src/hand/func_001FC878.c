struct VTE { short d; short pad; void (*pfn)(void *); };
struct P { char pad[0xC]; struct VTE *pvt; char pad2[0x40 - 0x10]; int n40; char pad3[0x4E - 0x44]; short n4E; unsigned short f50; unsigned short n52; char pad4[0x68 - 0x54]; long l68; };
struct G { char pad[0x1F0]; long l1F0; long l1F8; };
extern struct G g_sndmgr;
void func_001FCC30(void);
void func_001FBB30(void);
void func_002330D0(int, int, int, int, int, int, int, void (*)(void), long);
void func_001FB658(struct P *, int, int);
void func_001FC878(struct P *p)
{
    if (p->f50 & 0x1000) {
        p->pvt[1].pfn((char *)p + p->pvt[1].d);
        func_002330D0(0x524B5553, 7, p->n40, 0, 0, 0, 0, func_001FCC30, (long)p);
        func_001FB658(p, 0x1000, 0);
    }
    if (p->n52) return;
    if (p->f50 & 0x400) {
        p->pvt[1].pfn((char *)p + p->pvt[1].d);
        func_002330D0(0x524B5553, 8, p->n40, 0, 0, 0, 0, func_001FBB30, (long)p);
        func_001FB658(p, 0x400, 0);
    }
    if ((p->f50 & 0x800) && p->n4E <= 0)
        p->l68 += g_sndmgr.l1F0 - g_sndmgr.l1F8;
}
