typedef struct MSG { int n; int nKind; } MSG;
void PvAllocSwImpl__Fi(MSG *pmsg);

void func_00116A30(void *pv, int n)
{
    MSG msg;
    msg.n = n;
    msg.nKind = 0x10;
    PvAllocSwImpl__Fi(&msg);
}
