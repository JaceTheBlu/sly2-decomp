extern char g_sw[];
void func_00147E88(void *, int);
typedef struct S {
    char pad[0x10];
    int x10;
    int x14;
    char pad2[0x10];
    int x28;
    signed char ips;
    char x2D;
    long k : 4;
    unsigned long b : 8;
    unsigned int f : 1;
    char pad3[0x24];
    int x54;
} S;

void func_002313F0(S *p)
{
    p->x54 = -1;
    if (p->x10 == 0 && p->f)
        func_00147E88(g_sw, p->x14);
}
