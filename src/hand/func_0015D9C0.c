typedef struct CRef { int m_tagk; float m_g; } CRef;
struct X { char pad[0x110]; int i; };
struct G { char pad[0x3B58]; void *ap[9]; char pad2[0x4774 - 0x3B7C]; struct X *px; };
extern struct G g_sw;
extern char D_003D4A60[];
extern char D_002A5168[];
void func_002581C0(CRef *pref, void *p, void *q);
void func_00129EC8(CRef *pref);
float func_00245A18(float a, float b);
void func_0021ECD8(char *pch, char *fmt, ...);
void func_0015D9C0(char *pch)
{
    struct G *pg = &g_sw;
    void *p;
    if (pg->px && (p = pg->ap[pg->px->i]) != 0) {
        CRef ref;
        float g;
        int h, m;
        func_002581C0(&ref, p, D_003D4A60);
        g = ref.m_g;
        func_00129EC8(&ref);
        h = (int)(g / 3600.0f);
        m = (int)(func_00245A18(g, 3600.0f) / 60.0f);
        func_0021ECD8(pch, D_002A5168, h, m);
    }
}
