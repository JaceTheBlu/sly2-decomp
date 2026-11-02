struct AR { int cb; int cbAlign; };
struct X { int id; unsigned char b4; signed char cch; char pad[2]; unsigned short c; char pad2[2]; int *pv; unsigned int cqw; };
struct Y { char pad[0xC]; int *pv; };
void Read__18CBinaryInputStreamiPv(void *pbis, int cb, void *pv);
void Skip__18CBinaryInputStreami(void *pbis, int cb);
int func_0013FAD0(int cch, void *pw);
struct Y *func_001ED5D0(int id);
void *PvAllocSwImpl__Fi(struct AR *par);
void func_001ED278(int *p);
void func_001EA8A8(void *pbis, struct X *px)
{
    union { short aw[0x80]; struct AR ar; } u;
    unsigned int cb;
    Read__18CBinaryInputStreamiPv(pbis, 0x10, px);
    cb = px->c * sizeof(int);
    if (px->cch > 0) {
        Read__18CBinaryInputStreamiPv(pbis, px->cch * 2, u.aw);
        if (!func_0013FAD0(px->cch, u.aw)) {
            if (px->b4 != 1)
                Skip__18CBinaryInputStreami(pbis, cb);
            px->b4 = 0;
            return;
        }
    }
    if (px->b4 != 1) {
        struct Y *py = func_001ED5D0(px->id);
        if (py) {
            px->pv = py->pv;
            Skip__18CBinaryInputStreami(pbis, cb);
        } else {
            int *pn;
            u.ar.cb = cb;
            u.ar.cbAlign = 0x10;
            px->pv = PvAllocSwImpl__Fi(&u.ar);
            Read__18CBinaryInputStreamiPv(pbis, cb, px->pv);
            for (pn = px->pv; pn < px->pv + px->c; pn++)
                func_001ED278(pn);
        }
    }
    px->cqw = (cb + 15) >> 4;
}
