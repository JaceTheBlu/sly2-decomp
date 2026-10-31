struct VTE { short d; short pad; void (*pfn)(void *, int, int, int, int, int); };
struct O { char pad[0xC]; struct VTE *vt; char pad2[0x20]; float x30; };
extern float g_clock;
void func_001A5E28(struct O *p)
{
    if (p->x30 <= g_clock) {
        struct VTE *e = &p->vt[3];
        e->pfn((char *)p + e->d, 1, 1, 0, 0, 0);
    }
}
