struct CRef {
    int m_tagk;
    int m_tag;
    CRef() { m_tagk = -1; }
    ~CRef() { Decref(); }
    CRef &operator=(const CRef &);
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
struct TRIE { int pad; ENT *ae; char x8[1]; };
struct KEY { int c; unsigned short *a; };
struct OUT { ENT *pe; int n; };
struct AREQ { int cb; int cbAlign; AREQ(int c, int a) { cb = c; cbAlign = a; } };
struct G { char pad[0x3A18]; TRIE trie; };
extern "C" {
extern TRIE D_003E0EA8;
extern G g_sw;
extern char D_003D4A60[];
extern char D_002A4D88[];
extern char D_002A4D90[];
extern char D_002A4D98[];
extern char D_002A4DA0[];
short func_001D8720(void *, char *);
int func_001D7DA0(TRIE *, KEY *, OUT *);
CRef func_001D7ED8(TRIE *p, KEY *key, char *pb);
void *PvAllocStackImpl__FP7SWALLOC(const AREQ &);
void func_001AE5A0(void *, void *, int);
}
static inline CRef Lookup(KEY &k) { return func_001D7ED8(&D_003E0EA8, &k, D_003D4A60); }
static inline void *Alloc(int cb)
{
    AREQ req(cb, 0x10);
    return PvAllocStackImpl__FP7SWALLOC(req);
}
extern "C" KEY *func_00143410(int id)
{
    unsigned short as[8];
    KEY key;
    OUT out;
    OUT out2;
    TRIE *pt = &g_sw.trie;
    key.c = 0;
    key.a = as;
    as[0] = func_001D8720(pt->x8, D_002A4D88);
    as[2] = func_001D8720(pt->x8, D_002A4D90);
    as[4] = func_001D8720(pt->x8, D_002A4D98);
    as[5] = func_001D8720(pt->x8, D_002A4DA0);
    key.c = 1;
    func_001D7DA0(pt, &key, &out);
    ENT *pe1;
    for (int n = out.pe->iChild; n != 0; n = pe1->iSibling) {
        pe1 = &g_sw.trie.ae[n];
        key.c = 3;
        as[1] = pe1->ch;
        if (func_001D7DA0(&g_sw.trie, &key, &out2)) {
            ENT *pe2;
            for (int n2 = out2.pe->iChild; n2 != 0; n2 = pe2->iSibling) {
                pe2 = &g_sw.trie.ae[n2];
                as[3] = pe2->ch;
                CRef ref;
                for (int i = 0; i < 15; i++) {
                    as[6] = i;
                    key.c = 7;
                    ref = Lookup(key);
                    if (ref.m_tag == id) {
                        KEY *pk = (KEY *)Alloc(8);
                        func_001AE5A0(pk, &key, 8);
                        pk->a = (unsigned short *)Alloc(key.c * 2);
                        func_001AE5A0(pk->a, key.a, key.c * 2);
                        return pk;
                    }
                }
            }
        }
    }
    return 0;
}
