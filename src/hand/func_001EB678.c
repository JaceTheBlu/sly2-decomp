typedef unsigned long ulong;
struct B4 { char a[4]; };
struct MSG { int cb; int nKind; };
struct S3 { char pad[6]; unsigned char c6; };
struct Src { int x0; char pad4; unsigned char b5; unsigned char b6; char pad7; struct B4 b8; char padc[0xC]; struct S3 *p18; };
struct Dst { int x0; int x4; int x8; struct B4 bc; int c; ulong *a; };
void *PvAllocSwClearImpl__FP7SWALLOC(struct MSG *);
ulong func_001EA6C8(struct S3 *, int, int);
void func_001EB678(struct Src *ps, struct Dst *pd)
{
    struct S3 *p;
    struct MSG msg;
    int i;
    pd->x0 = ps->x0;
    pd->x4 = ps->b6;
    pd->x8 = ps->b5;
    pd->bc = ps->b8;
    p = ps->p18;
    {
        int c = p->c6;
        pd->c = c;
        msg.cb = c * 8;
    }
    msg.nKind = 0x10;
    pd->a = PvAllocSwClearImpl__FP7SWALLOC(&msg);
    for (i = 0; i < pd->c; i++)
    {
        ulong *pe = (ulong *)((i << 3) + (int)pd->a);
        *pe = func_001EA6C8(p, i, 0);
    }
}
