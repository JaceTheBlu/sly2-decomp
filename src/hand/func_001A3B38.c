struct G { char pad[0x3D5C]; int x3d5c; };
extern struct G g_sw;
extern int D_003E19E4;
struct S { char pad[0xE0]; int xe0; char pad2[0x78]; int x15c; int x160; };
void func_001A3B38(struct S *p)
{
    if (!p->x160) g_sw.x3d5c++;
    if (!p->x15c && p->xe0) D_003E19E4 = 1;
}
