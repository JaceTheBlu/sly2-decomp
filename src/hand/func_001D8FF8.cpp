struct CRef {
    int m_tagk;
    union { int m_tag; float m_g; };
    CRef() { m_tagk = -1; }
    CRef(const CRef &);
    ~CRef() { Decref(); }
    CRef &operator=(const CRef &);
    void Decref();
};
struct KEY;
struct GS { char pad[0x3B2C]; KEY *k[7]; };
struct DISP1 { unsigned long dx : 12; unsigned long dy : 11; unsigned long rest : 41; };
struct DISP2 { unsigned int dx : 12; unsigned int dy : 11; unsigned long rest : 41; };
struct GSR { char pad[0x18]; DISP1 d1; char pad20[0x40 - 0x20]; DISP2 d2; };
extern "C" {
extern GS g_sw;
extern char g_sndmgr[];
extern int D_003DD050;
extern GSR D_002DEB80;
CRef func_002581C0(KEY *, char *);
int func_001A2C98(void);
void func_001A2BD0(int);
void func_001FE9C8(void *, int);
void func_001FEA60(void *, int, int, float);
unsigned int func_0023E1C8(float);
}
static inline int GetInt(KEY *k, char *pb) { return func_002581C0(k, pb).m_tag; }
static inline float GetFloat(KEY *k, char *pb) { return func_002581C0(k, pb).m_g; }
extern "C" void func_001D8FF8(char *pb)
{
    if (g_sw.k[0] && func_001A2C98() >= 2)
        func_001A2BD0(GetInt(g_sw.k[0], pb));
    if (g_sw.k[1])
        func_001FE9C8(g_sndmgr, GetInt(g_sw.k[1], pb));
    if (g_sw.k[2])
        func_001FEA60(g_sndmgr, 1, 1, 1.0f - GetFloat(g_sw.k[2], pb));
    if (g_sw.k[3]) {
        func_001FEA60(g_sndmgr, 0, 1, 1.0f - GetFloat(g_sw.k[3], pb));
        func_001FEA60(g_sndmgr, 3, 1, 1.0f - GetFloat(g_sw.k[3], pb));
    }
    if (g_sw.k[4])
        D_003DD050 = GetInt(g_sw.k[4], pb);
    if (g_sw.k[5]) {
        float f = GetFloat(g_sw.k[5], pb);
        GSR *p = &D_002DEB80;
        p->d1.dx = p->d2.dx = func_0023E1C8(f + 636.0f);
    }
    if (g_sw.k[6]) {
        float f = GetFloat(g_sw.k[6], pb);
        GSR *p = &D_002DEB80;
        p->d1.dy = p->d2.dy = func_0023E1C8(f + 50.0f) & ~1;
    }
}
