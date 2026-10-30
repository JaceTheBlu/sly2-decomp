struct G { char pad[0x228]; void *p228; };
extern struct G g_sndmgr;
int func_001FE990(struct G *);
void func_001FC2E0(void *, int, float);
void func_001FC380(void *, int, int);
void func_001FF108(int a, int b, int c, float g)
{
    int r = func_001FE990(&g_sndmgr);
    void *p = g_sndmgr.p228;
    func_001FC2E0(p, r, g);
    func_001FC380(p, r, c);
}
