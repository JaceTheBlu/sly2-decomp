struct E { int a; void *pv; int b; void *powner; int dle; };
struct P { char pad[0x24]; int x24; char pad2[0x34 - 0x28]; int dl; };
extern int D_003DA790;
extern struct E D_003DA798[];
void func_0011A058(int *pdle);
void func_0011A098(int *pdl, struct E *pe);
void func_00226E88(void *a, int b, int c, void *d, struct E *pe, int *pb);
void MeasureCrvl__FP4CRVL(struct E *pe);
int func_001ED960(struct P *p, void *a1, void *a2)
{
    struct E e;
    struct E *pe;
    if (D_003DA790 < 0x200) {
        pe = &D_003DA798[D_003DA790++];
        func_0011A058(&pe->dle);
        func_0011A098(&p->dl, pe);
        pe->powner = p;
    } else {
        pe = &e;
    }
    func_00226E88(a2, 0xD, 1, a1, pe, &pe->b);
    pe->pv = &p->x24;
    MeasureCrvl__FP4CRVL(pe);
    return 1;
}
