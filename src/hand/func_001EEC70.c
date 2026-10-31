struct MSG { int cb; int nKind; };
struct S { int a, b; void *ap[8]; };
int func_001EF6F0(void);
void *PvAllocSwImpl__Fi(struct MSG *pmsg);
void func_001EEC70(struct S *p)
{
    unsigned int i;
    struct MSG msg;
    for (i = 0; i < 8; i++) {
        msg.cb = func_001EF6F0();
        msg.nKind = 0x10;
        p->ap[i] = PvAllocSwImpl__Fi(&msg);
    }
}
