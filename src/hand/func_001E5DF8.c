typedef int qword __attribute__((mode(TI)));
struct MSG { int cb; int nKind; };
struct P {
    char pad[0xE0];
    int fE0;
    int nE4;
    int c;
    int *aE;
    float *aF0;
    qword *aF4;
    char pad2[0x140 - 0xF8];
    qword *a140;
    qword *a144;
};
void func_00231768(struct P *, void *);
int func_00117D00(void *);
int func_00117C20(void *);
void *PvAllocSwImpl__Fi(struct MSG *);
void Read__18CBinaryInputStreamiPv(void *, int, void *);
void ReadVector__18CBinaryInputStreamP6VECTOR(void *, qword *);
void func_0013F810(struct P *, void *);
void func_001E6180(struct P *);
void func_001E5DF8(struct P *p, void *pbis)
{
    struct MSG msg;
    int i;
    func_00231768(p, pbis);
    p->fE0 = func_00117D00(pbis);
    p->nE4 = func_00117D00(pbis);
    p->c = func_00117C20(pbis);
    msg.cb = p->c * 4;
    msg.nKind = 0x10;
    p->aE = PvAllocSwImpl__Fi(&msg);
    msg.cb = p->c * 4;
    msg.nKind = 0x10;
    p->aF0 = PvAllocSwImpl__Fi(&msg);
    msg.cb = p->c * 16;
    msg.nKind = 0x10;
    p->aF4 = PvAllocSwImpl__Fi(&msg);
    Read__18CBinaryInputStreamiPv(pbis, p->c * 4, p->aE);
    for (i = 0; i < p->c; i++)
        ReadVector__18CBinaryInputStreamP6VECTOR(pbis, &p->aF4[i]);
    if (p->fE0) {
        msg.cb = p->c * 16;
        msg.nKind = 0x10;
        p->a140 = PvAllocSwImpl__Fi(&msg);
        msg.cb = p->c * 16;
        msg.nKind = 0x10;
        p->a144 = PvAllocSwImpl__Fi(&msg);
        for (i = 0; i < p->c; i++)
            ReadVector__18CBinaryInputStreamP6VECTOR(pbis, &p->a140[i]);
        for (i = 0; i < p->c; i++)
            ReadVector__18CBinaryInputStreamP6VECTOR(pbis, &p->a144[i]);
    }
    func_0013F810(p, pbis);
    func_001E6180(p);
}
