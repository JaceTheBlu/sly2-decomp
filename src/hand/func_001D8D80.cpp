struct CRef {
    int m_tagk;
    int m_tag;
    CRef() { m_tagk = -1; }
    CRef(const CRef &);
    ~CRef() { Decref(); }
    CRef &operator=(const CRef &);
    void Decref();
};
struct FRAME {
    int a[4];
    FRAME();
    ~FRAME();
};
struct KEY;
struct TRIE;
struct KEYS { KEY *a[11]; };
struct GS { char pad[0x3B2C]; KEY *k[11]; };
extern "C" {
extern GS g_sw;
extern TRIE D_003E0EA8;
int func_001D7D30(TRIE *, char *);
CRef func_001D7ED8(TRIE *, KEY *, char *);
CRef func_00258200(KEY *, CRef *, char *);
void func_002333B4(void *, int, unsigned int);
void func_001D54B8(void);
}
static inline CRef Get(KEY *k, char *pb) { return func_001D7ED8(&D_003E0EA8, k, pb); }
static inline CRef Set(KEY *k, CRef *r, char *pb) { return func_00258200(k, r, pb); }
extern "C" void func_001D8D80(char *pb, int f)
{
    FRAME frame;
    KEY *keys[11] = { g_sw.k[0], g_sw.k[7], g_sw.k[10], g_sw.k[8], g_sw.k[9], g_sw.k[1], g_sw.k[2], g_sw.k[3], g_sw.k[4], g_sw.k[5], g_sw.k[6] };
    CRef aref[11];
    unsigned int i;
    if (f && !func_001D7D30(&D_003E0EA8, pb))
        f = 0;
    if (f) {
        for (i = 0; i < 11; i++)
            aref[i] = Get(keys[i], pb);
    }
    func_002333B4(pb, 0, 0x5400);
    func_001D54B8();
    if (f) {
        for (i = 0; i < 11; i++)
        {
            CRef ref(aref[i]);
            const CRef &r = Set(keys[i], &ref, pb);
        }
    }
}
