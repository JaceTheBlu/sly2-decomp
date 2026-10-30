struct G;
extern struct G g_sw;
struct Z { char pad[0xF8]; int xF8; };
struct Y { char pad[0x74]; int c; struct Z *a[1]; };
struct X { char pad[0xF38]; struct Y *py; };
struct X *func_001C4840(struct G *g);
int func_00132B10(void *p, int cid);
char *func_0013E368(struct G *g, int id);
void func_0021ED58(char *dst, char *src);
void func_002111F0(char *dst, int i)
{
    struct G *g = &g_sw;
    struct X *p = func_001C4840(g);
    if (p && func_00132B10(p, 0x34)) {
        struct Y *y = p->py;
        if (y && i < y->c)
            func_0021ED58(dst, func_0013E368(g, y->a[i]->xF8));
    }
}
