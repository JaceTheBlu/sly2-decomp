struct E { int x0; int x4; int x8; };
extern struct E D_002C3288[];
struct Z { int x0; int x4; };
struct Y { char pad[0x224]; int x224; char pad228[0x1C]; struct Z *x244; };
struct X { char pad[0x4C8]; int x4C8; char pad4cc[0x9A0 - 0x4CC]; struct Y *x9A0; char pad9a4[0x1318 - 0x9A4]; int x1318; };
extern char g_sw[];
struct X *func_001C4840(void *);
int func_00132B10(void *, int);
char *func_0013E368(void *, int);
void func_0021ED58(char *, char *);
void func_00211420(char *pch)
{
    int id = -1;
    struct X *x = func_001C4840(g_sw);
    if (x && func_00132B10(x, 0x34)) {
        struct Y *y = x->x9A0;
        if (y) {
            int k = x->x4C8;
            if (k == 0xC) {
                if (func_00132B10(y, 0x5E))
                    id = D_002C3288[y->x244->x4].x4;
                else if (func_00132B10(y, 0x5C))
                    id = y->x224;
                else
                    id = x->x1318;
            }
        }
    }
    if (id != -1)
        func_0021ED58(pch, func_0013E368(g_sw, id));
    else
        *pch = 0;
}
