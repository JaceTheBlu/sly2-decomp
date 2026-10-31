typedef struct MARK { int a[4]; } MARK;
typedef struct MSG { int cb; int nKind; int k; int **pp; } MSG;
struct O { char pad[0x28]; long bits; };
struct S { char pad[0xE4]; char aE4[0x18]; char aFC[0x10]; struct O *p10C; int c; void *a; void *cur; int x11C; char pad2[0x164 - 0x120]; int flags; };
void func_00231768(struct S *p, void *pbis);
void func_00117FD0(void *pbis, void *pv);
void ReadVbsp__18CBinaryInputStreamPiPP4VBSP(void *pbis, void *pv, void *pv2);
MARK *func_001AE478(MARK *pm);
void _$_18CBinaryInputStream(MARK *pm, int n);
void *PvAllocStackImpl__FP7SWALLOC(MSG *pmsg);
void *PvAllocSwCopyImpl__FP7SWALLOCPv(MSG *pmsg, void *pv);
void func_00221818(struct S *p, int id);
void LoadOptionsFromBrx__FPvP18CBinaryInputStream(struct S *p, void *pbis);
void func_00221940(struct S *p);
void __19CLoadCollectorArray(MSG *pmsg);
void func_002317E0(struct S *p, void *pbis, MSG *pmsg);
void func_00220FD0(struct S *p, void *pbis)
{
    MARK mark;
    MSG msg;
    void *pv;
    func_00231768(p, pbis);
    func_00117FD0(pbis, p->aE4);
    ReadVbsp__18CBinaryInputStreamPiPP4VBSP(pbis, p->aE4, p->aFC);
    func_001AE478(&mark);
    {
        MSG *pm = &msg;
        pm->cb = 0x240;
        pm->nKind = 0x10;
        p->a = PvAllocStackImpl__FP7SWALLOC(pm);
    }
    func_00221818(p, 0x30);
    LoadOptionsFromBrx__FPvP18CBinaryInputStream(p, pbis);
    func_00221940(p);
    {
        MSG *pm = &msg;
        pm->cb = p->c * 0x90;
        pm->nKind = 0x10;
        pv = PvAllocSwCopyImpl__FP7SWALLOCPv(pm, p->a);
    }
    p->x11C = 1;
    p->a = pv;
    p->cur = pv;
    __19CLoadCollectorArray(&msg);
    func_002317E0(p, pbis, &msg);
    switch (msg.k) {
    case 0:
        break;
    case 1:
        p->p10C = (struct O *)*msg.pp;
        p->p10C->bits |= 1L << 57;
        break;
    }
    if (!p->p10C) p->flags &= ~2;
    _$_18CBinaryInputStream(&mark, 2);
}
