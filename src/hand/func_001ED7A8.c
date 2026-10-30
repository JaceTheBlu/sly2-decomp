struct VTE { short d; short pad; void (*pfn)(void *, char *); };
struct O { int pad[3]; struct VTE *vt; char pad2[0x30 - 0x10]; void *p30; };
struct REG { int a[4]; struct O *(*pfnNew)(void); };
extern struct REG D_002BAAE8[];
int func_00117C20(void *pbis);
void Read__18CBinaryInputStreamiPv(void *pbis, int cb, char *buf);
struct O *func_001ED7A8(void *pv, void *pbis)
{
    char buf[0x20];
    int i = func_00117C20(pbis);
    struct O *p;
    if (i == -1) return 0;
    p = (D_002BAAE8 + i)->pfnNew();
    p->p30 = pv;
    Read__18CBinaryInputStreamiPv(pbis, 0x20, buf);
    p->vt[7].pfn((char *)p + p->vt[7].d, buf);
    return p;
}
