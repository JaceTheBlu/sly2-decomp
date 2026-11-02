extern struct CLOCK { float a[16]; } g_clock;
typedef struct {
    char pad[0x28];
    int state;
    float t;
    char pad30[0x48 - 0x30];
    int c;
    char pad4c[0x24C - 0x4C];
    int i;
} OBJ;
void func_001DC260(OBJ *, int);
void func_001DBBE0(OBJ *, int);
void *func_001FBB90(int);
void func_001FB2F8(void *, int);
void func_001DC4B0(OBJ *p, unsigned int n)
{
    if (n == p->state)
        return;
    p->state = n;
    p->t = g_clock.a[15];
    switch (n) {
    case 0:
        func_001DC260(p, 1);
        break;
    case 4:
        func_001DC260(p, 0);
        break;
    case 1:
    case 2:
    case 3:
        if (p->i > 0) {
            func_001DBBE0(p, p->i - 1);
            func_001FB2F8(func_001FBB90(0x35), 0);
        } else {
            func_001FB2F8(func_001FBB90(0x36), 0);
        }
        break;
    case 5:
    case 6:
    case 7:
        if (p->i < p->c - 1) {
            func_001DBBE0(p, p->i + 1);
            func_001FB2F8(func_001FBB90(0x35), 0);
        } else {
            func_001FB2F8(func_001FBB90(0x36), 0);
        }
        break;
    }
}
