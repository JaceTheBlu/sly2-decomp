struct E { int n; int pad[3]; };
struct P { char pad[0x404]; struct E ae[8]; int c484; int i488; };
void __1RiiPPv(void *, int, int, int *);
void *func_001F1EB8(void *r, struct P *p)
{
    int buf[8];
    int n = 0;
    int i;
    for (i = p->i488; i < p->c484; i++) buf[n++] = p->ae[i].n;
    __1RiiPPv(r, n, 6, buf);
    return r;
}
