struct AR { int cb; int cbAlign; };
struct E { int id; unsigned char b4; char pad[0x20 - 5]; };
extern int D_003DCFF8;
extern struct E *D_003DCFFC;
extern int D_003DCF9C;
int func_00117C20(void *pbis);
void *PvAllocStackClearImpl__FP7SWALLOC(struct AR *par);
void func_001EA8A8(void *pbis, struct E *pe);
void func_001EAE40(void *pbis)
{
    struct AR ar;
    int i = 0;
    D_003DCFF8 = func_00117C20(pbis);
    ar.cb = D_003DCFF8 * sizeof(struct E);
    ar.cbAlign = 0x10;
    D_003DCFFC = PvAllocStackClearImpl__FP7SWALLOC(&ar);
    D_003DCF9C = 0;
    for (; i < D_003DCFF8; i++) {
        func_001EA8A8(pbis, &D_003DCFFC[i]);
        if (D_003DCFFC[i].b4 == 1) D_003DCF9C++;
    }
    if (D_003DCF9C < D_003DCFF8 - D_003DCF9C) D_003DCF9C = D_003DCFF8 - D_003DCF9C;
}
