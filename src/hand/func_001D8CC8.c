struct MSG { int cb; int nKind; };
typedef struct { int c; short *a; } SA;
void *PvAllocStackImpl__FP7SWALLOC(struct MSG *pmsg);
void func_001AE5A0(void *, void *, int);
SA *func_001D8CC8(SA *p1, SA *p2)
{
    struct MSG msg;
    SA *r;
    int c;
    msg.cb = 8;
    msg.nKind = 0x10;
    r = (SA *)PvAllocStackImpl__FP7SWALLOC(&msg);
    c = p1->c + p2->c;
    r->c = c;
    msg.cb = c * 2;
    msg.nKind = 0x10;
    r->a = (short *)PvAllocStackImpl__FP7SWALLOC(&msg);
    func_001AE5A0(r->a, p1->a, p1->c * 2);
    func_001AE5A0(r->a + p1->c, p2->a, p2->c * 2);
    return r;
}
