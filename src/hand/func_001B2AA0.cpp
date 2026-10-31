struct CTX { int a[4]; CTX(); ~CTX(); };
struct AREQ { int cb; int align; AREQ(int c, int a) { cb = c; align = a; } };
struct S { int x0; int x4; int x8; int xC; int x10; };
extern "C" {
char *PvAllocStackImpl__FP7SWALLOC(const AREQ &r);
void func_001AE5A0(void *dst, void *src, int cb);
}
static inline char *Alloc(int cb, int align) { return PvAllocStackImpl__FP7SWALLOC(AREQ(cb, align)); }

extern "C" void func_001B2AA0(S *p, int cb, char *pb)
{
    int ch = p->x4;
    if (ch != 0x10) return;
    if (p->xC == 1) return;
    CTX ctx;
    char *pbCur = pb;
    int chunk = p->xC << 10;
    char *tmp = Alloc(chunk, 0x10);
    int cbCur = cb;
    while (cbCur) {
        int i = 0, k = 0, off;
        for (off = 0; off < chunk; off += p->x10) {
            func_001AE5A0(tmp + ((i << 10) + k * p->x10), pbCur + off, p->x10);
            i++;
            if (i >= p->xC) {
                k++;
                i = 0;
            }
        }
        func_001AE5A0(pbCur, tmp, chunk);
        pbCur += chunk;
        cbCur -= chunk;
    }
}
