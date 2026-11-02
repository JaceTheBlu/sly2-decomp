typedef unsigned long ulong __attribute__((mode(DI)));
struct GIFS;
struct FONT { char pad[0x3C]; int n3C; ulong q40; int pad48[2]; ulong q50; };
void func_00166BD8(struct GIFS *, int, int, int);
void func_00166E90(struct GIFS *, int, ulong);
void func_00166EF0(struct GIFS *, int, ulong);
int FEnsureLoaded__8CFontBrxP4GIFS(struct FONT *, struct GIFS *);
void func_0015F220(struct FONT *pfont, float *prc, struct GIFS *pgifs)
{
    int fFlush;
    if (prc) {
        int x1, y1, x0, y0;
        x1 = (int)((prc[0] + prc[2] * 512.0f) * 0.0015625f) - 1;
        y1 = (int)((prc[1] + prc[3]) * 0.45454547f) - 1;
        x0 = (int)(prc[0] * 0.8f);
        y0 = (int)(prc[1] * 0.45454547f);
        func_00166BD8(pgifs, 0, 1, 0xE);
        func_00166E90(pgifs, 0x40, (ulong)x0 | ((ulong)x1 << 16) | ((ulong)y0 << 32) | ((ulong)y1 << 48));
    }
    fFlush = FEnsureLoaded__8CFontBrxP4GIFS(pfont, pgifs);
    func_00166BD8(pgifs, 6, 1, 0xE);
    if (fFlush)
        func_00166E90(pgifs, 0x3F, 0);
    func_00166E90(pgifs, 0x47, pfont->n3C ? pfont->q40 : 0x31001);
    func_00166E90(pgifs, 0x42, 0x44);
    func_00166E90(pgifs, 6, pfont->q50);
    func_00166E90(pgifs, 0x14, 0x60);
    func_00166E90(pgifs, 8, 5);
    func_00166E90(pgifs, 0, 0x1D6);
    func_00166EF0(pgifs, 5, 0x43431);
}
