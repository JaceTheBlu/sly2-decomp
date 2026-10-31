struct AR { int cb; int cbAlign; };
struct X { int id; unsigned char b4; signed char cch; char pad[0x10 - 6]; unsigned int cb; void *pv; unsigned int cqw; };
struct Y { char pad[0x14]; void *pv; };
void Read__18CBinaryInputStreamiPv(void *pbis, int cb, void *pv);
void Skip__18CBinaryInputStreami(void *pbis, int cb);
int func_0013FAD0(int cch, void *pw);
struct Y *func_001ED4E0(int id);
void *PvAllocSwImpl__Fi(struct AR *par);
void func_001EAF50(void *pbis, struct X *px)
{
    union { short aw[0x80]; struct AR ar; } u;
    Read__18CBinaryInputStreamiPv(pbis, 0x18, px);
    if (px->cch > 0) {
        Read__18CBinaryInputStreamiPv(pbis, px->cch * 2, u.aw);
        if (!func_0013FAD0(px->cch, u.aw)) {
            if (px->b4 != 1) {
                Skip__18CBinaryInputStreami(pbis, px->cb);
                px->pv = 0;
            }
            px->b4 = 0;
            return;
        }
    }
    if (px->b4 != 1) {
        struct Y *py = func_001ED4E0(px->id);
        if (py) {
            px->pv = py->pv;
            Skip__18CBinaryInputStreami(pbis, px->cb);
        } else {
            u.ar.cb = px->cb;
            u.ar.cbAlign = 0x10;
            px->pv = PvAllocSwImpl__Fi(&u.ar);
            Read__18CBinaryInputStreamiPv(pbis, px->cb, px->pv);
        }
    }
    px->cqw = (px->cb + 15) >> 4;
}
