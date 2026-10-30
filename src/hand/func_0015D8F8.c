typedef struct CRef { int m_tagk; int m_tag; } CRef;
struct X { char pad[0x110]; int i; };
struct G { char pad[0x3B7C]; void *ap[9]; char pad2[0x4774 - 0x3BA0]; struct X *px; };
extern struct G g_sw;
extern char D_003D4A60[];
extern void *D_002BE2F8[];
extern char D_002A5160[];
void func_002581C0(CRef *pref, void *p, void *q);
void func_00129EC8(CRef *pref);
int func_001DAEA8(void *p);
void func_0021ECD8(char *pch, char *fmt, ...);
void func_0015D8F8(char *pch)
{
    struct G *pg = &g_sw;
    void *p;
    if (pg->px && (p = pg->ap[pg->px->i]) != 0) {
        CRef ref;
        int n;
        func_002581C0(&ref, p, D_003D4A60);
        n = ref.m_tag;
        func_00129EC8(&ref);
        n = n * 95 / 100;
        if (func_001DAEA8(D_002BE2F8[pg->px->i]))
            n += 5;
        func_0021ECD8(pch, D_002A5160, n);
    }
}
