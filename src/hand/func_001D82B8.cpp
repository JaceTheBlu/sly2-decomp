struct CRef {
    int m_tagk;
    int m_tag;
    CRef() { m_tagk = -1; }
    CRef(const CRef &);
    ~CRef() { Decref(); }
    void Decref();
};
struct ENT {
    short ch;
    signed char kind;
    unsigned char fBits;
    unsigned short ib;
    unsigned short iChild;
    unsigned short iSibling;
};
struct OBJ { int c; ENT *ae; char ht[1]; };
struct G { char pad[0x3B7C]; void *apv[9]; };
extern G g_sw;
extern int D_002C2DC0[];
extern char D_002A78F0[];
CRef func_002581C0(void *, unsigned char *);
extern "C" int func_001D8720(void *, char *);
static inline int NGet(void *pv, unsigned char *pb)
{
    CRef ref = func_002581C0(pv, pb);
    return ref.m_tag;
}
static inline int Clamp(int n, int lo, int hi)
{
    if (n < lo)
        return lo;
    if (n > hi)
        return hi;
    return n;
}
static inline int NFind(OBJ *p, char *pch) { return func_001D8720(p->ht, pch); }
extern "C" int func_001D82B8(OBJ *p, unsigned char *pb)
{
    int sum = 0;
    int total = 0;
    int i;
    int k;
    for (i = 0; i < 9; i++) {
        void *pv = g_sw.apv[i];
        int w = D_002C2DC0[i];
        total += w * 100;
        if (pv)
            sum += NGet(pv, pb) * w;
    }
    k = NFind(p, D_002A78F0);
    total += 0xD0;
    for (int ie = 0; ie < p->c; ie++) {
        ENT *pe = &p->ae[ie];
        if (pe->kind == 4 && pe->ch == k) {
            unsigned char *pv = pb + pe->ib;
            if (pe->fBits) {
                int c = pe->fBits;
                int j;
                for (j = 0; j < c; j++) {
                    unsigned char b = 1 << (j % 8);
                    if (pv[j / 8] & b)
                        sum += 0x1A;
                }
            } else {
                if (*pv)
                    sum += 0x1A;
            }
        }
    }
    if (sum == 0)
        return 0;
    if (sum == total)
        return 100;
    {
        return Clamp(sum * 100 / total, 1, 99);
    }
}
