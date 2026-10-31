// UpdateCd: matched. Keys: `int lsn = D_002A2E5C; lsn += 0xCA0;` (fixes s0/s1), CRC table via a local `unsigned int *tbl` with a byte offset `(char *)tbl + (idx << 2)` (gives addu v0,t1,v0).
extern int D_002BD4C0;
extern int D_003DD0E4;
extern char D_003DA4F0[];
extern int D_002A2E5C;
extern unsigned char D_002DD680[];
extern char D_002A2E50[];
extern unsigned int D_002A2E68[];
extern unsigned int D_002A2E60;
extern "C" {
int FValidCdMmode__Fv(void);
void func_001DD6C8(void *p);
int func_001DD780(void *p);
void func_001DD728(void *p);
int func_00242840(int lsn, int c, void *buf, void *mode);
int func_0014BD30(int n);
}
static inline unsigned int UCrc(unsigned char *pb, int cb)
{
    unsigned int *tbl = D_002A2E68;
    unsigned int crc = 0xFFFFFFFF;
    while (cb--)
        crc = *(unsigned int *)((char *)tbl + (((crc ^ *pb++) & 0xFF) << 2)) ^ (crc >> 8);
    return crc;
}
void UpdateCd(void)
{
    int cds = D_002BD4C0;
    switch (cds) {
    case 3:
        if (D_003DD0E4 && !FValidCdMmode__Fv()) {
            func_001DD6C8(D_003DA4F0);
            D_002BD4C0 = 1;
        }
        break;
    case 1:
        if (func_001DD780(D_003DA4F0)) {
            int lsn = D_002A2E5C;
            lsn += 0xCA0;
            if (FValidCdMmode__Fv() && func_00242840(lsn, 1, D_002DD680, D_002A2E50) == cds)
                D_002BD4C0 = 2;
        }
        break;
    case 2:
        if (func_0014BD30(0)) {
            if (UCrc(D_002DD680, 0x800) != D_002A2E60) {
                D_002BD4C0 = 1;
            } else {
                func_001DD728(D_003DA4F0);
                D_002BD4C0 = 3;
            }
        }
        break;
    }
}
