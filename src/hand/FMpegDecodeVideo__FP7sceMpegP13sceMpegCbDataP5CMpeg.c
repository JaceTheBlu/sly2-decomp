struct S { char pad[0x160]; char x160[0x14]; int x174; char pad2[8]; char x180[0x10]; };
extern char D_002D4220[];
int func_001B41D0(struct S *p, int n);
void Update__10CMpegAudio(void *p);
void func_002333B4(void *p, int c, int n);
void func_0013D7D0(void *p, int n, void *b);
void func_0013D818(void *p, int n);
void func_0013D6A8(void *p, int n, void *b);
int FMpegDecodeVideo__FP7sceMpegP13sceMpegCbDataP5CMpeg(int a, int b, struct S *p)
{
    void *buf[16];
    while (p->x174 < 0x1000) {
        int v = func_001B41D0(p, 1);
        if (v == 2) {
            func_002333B4(buf, 0, 0x40);
            func_0013D7D0(p->x160, 0x40 - p->x174 % 32, buf);
            break;
        }
        if (v == 1) Update__10CMpegAudio(p->x180);
    }
    buf[0] = D_002D4220;
    func_0013D818(p->x160, 0);
    func_0013D6A8(p->x160, 0, buf);
    return 1;
}
