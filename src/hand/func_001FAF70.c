typedef struct MSG { int cb; int nKind; } MSG;
void *PvAllocSwClearImpl__FP7SWALLOC(MSG *pmsg);
struct E { int n; float a; float b; float c; int d; };
struct E *func_001FAF70(void)
{
    MSG msg;
    struct E *pe;
    msg.cb = sizeof(struct E);
    msg.nKind = 0x10;
    pe = PvAllocSwClearImpl__FP7SWALLOC(&msg);
    pe->n = -1;
    pe->a = 300.0f;
    pe->b = 3000.0f;
    pe->c = 1.0f;
    return pe;
}
