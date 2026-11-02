struct S { int state; int x4; char x8[0x28]; char x30[0x10]; int x40; char pad[0xC]; char x50[0x10]; int x60; char pad2[0xC]; char x70[0x10]; };
int func_0013D7D0(void *p, int cb, unsigned char *pb);
int func_001B29D0(void *a, void *b);
int FAccept__10CMpegAudioiPUc(struct S *p, int cb, unsigned char *pb)
{
    int n;
    int id;
    if (p->state == 0) return 0;
    id = pb[3];
    if (p->x4 == -1) p->x4 = id;
    if (p->x4 != id) return 1;
    cb -= 4;
    pb += 4;
    if (p->state == 1) {
        n = func_0013D7D0(p->x30, cb, pb);
        cb -= n;
        pb += n;
        if (p->x40 > 0) return 1;
        if (func_001B29D0(p->x70, p->x8)) p->state = 2;
        else p->state = 0;
    }
    if (p->x60 >= cb) {
        func_0013D7D0(p->x50, cb, pb);
        return 1;
    }
    return 0;
}
