struct E;
struct S { char pad[0xF8]; int xF8; int xFC; int x100; struct E *x104; struct E *x108; int *x10C; int x110; int x114; };
struct G { char pad[0x3D70]; int x3D70; };
extern struct G g_sw;
void func_001C18B8(int n, struct E *a, int key);
void func_001C1968(struct S *p, int key)
{
    int i;
    for (i = 0; i < p->xFC; i++) {
        if (p->x10C[i] == key) break;
    }
    p->x10C[i] = 0;
    func_001C18B8(p->x100, p->x104, i);
    func_001C18B8(p->x100, p->x108, i);
    p->xF8--;
    p->x100 -= 2;
    p->x114 = ++g_sw.x3D70;
}
