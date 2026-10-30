struct S { char pad[0x1C]; int f; };
extern char D_002DEB30[], g_sw[], D_003D9ED0[];
extern char D_002C01D0[], D_002C01F0[], D_002C0210[];
void func_001619A0(void *p, int a, int b);
void *func_001C4840(void *p);
int func_00132EA0(void *p);
void func_001AF4D8(void *p, int a, int b, int c, char *s);
void func_001B0740(struct S *p)
{
    char *s;
    func_001619A0(D_002DEB30, 0x29, 0);
    switch (func_00132EA0(func_001C4840(g_sw))) {
    case 0x35: s = D_002C01D0; break;
    case 0x37: s = D_002C01F0; break;
    case 0x36: s = D_002C0210; break;
    default: return;
    }
    func_001AF4D8(D_003D9ED0, 0, 0, 0, s);
    if (p) p->f |= 2;
}
