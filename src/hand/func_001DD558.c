extern struct CLOCK { float a[16]; } g_clock;
typedef struct {
    char pad[0x28];
    int state;
    float t;
    char pad30[0x48 - 0x30];
    int c;
    char pad4c[0x118 - 0x4C];
    int i;
} OBJ;
void func_001DD300(OBJ *, int);
void func_001DCE90(OBJ *, int);
void *func_001FBB90(int);
void func_001FB2F8(void *, int);
void func_001DD558(OBJ *p, unsigned int n)
{
    if (n == p->state)
        return;
    p->state = n;
    p->t = g_clock.a[15];
    switch (n) {
    case 0:
        if (p->c)
            func_001DD300(p, 1);
        break;
    case 4:
        func_001DD300(p, 0);
        break;
    case 1:
    case 2:
    case 3:
        if (p->i > 0) {
            func_001DCE90(p, p->i - 1);
            func_001FB2F8(func_001FBB90(0x35), 0);
        }
        break;
    case 5:
    case 6:
    case 7:
        if (p->i < p->c - 1) {
            func_001DCE90(p, p->i + 1);
            func_001FB2F8(func_001FBB90(0x35), 0);
        }
        break;
    }
}
