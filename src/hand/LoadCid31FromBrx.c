typedef struct MSG { int cb; int nKind; } MSG;
void *PvAllocSwClearImpl__FP7SWALLOC(MSG *pmsg);
static inline void *PvAllocMsg(MSG *pmsg, int cb, int nKind) { pmsg->cb = cb; pmsg->nKind = nKind; return PvAllocSwClearImpl__FP7SWALLOC(pmsg); }
struct C { int a[4]; };
struct VTE { short d; short pad; void (*pfn)(); };
struct O { int a[3]; struct VTE *vt; int pad[6]; unsigned long fl; };
struct DA { int n0; int cMax; int c; struct O **a; };
struct S { char pad[0xE0]; int c; struct O **apo; };
void func_001AE478(struct C *);
void _$_18CBinaryInputStream(struct C *, int);
void LoadAloFromBrx__FP3ALOP18CBinaryInputStream(struct S *p, void *q);
void __19CLoadCollectorArray(struct DA *pda);
void func_002317E0(struct S *p, void *q, struct DA *pda);
int FIsBasicDerivedFrom__FP5BASIC3CID(void *p, int n);
void LoadCid31FromBrx(struct S *p, void *q)
{
    struct C ctx;
    struct DA da;
    MSG msg;
    int i;
    LoadAloFromBrx__FP3ALOP18CBinaryInputStream(p, q);
    func_001AE478(&ctx);
    __19CLoadCollectorArray(&da);
    func_002317E0(p, q, &da);
    p->apo = PvAllocMsg(&msg, da.c * 4, 0x10);
    for (i = 0; i < da.c; i++) {
        struct O *o = da.a[i];
        o->fl |= 0x200000000000000L;
        if (!FIsBasicDerivedFrom__FP5BASIC3CID(o, 0x1E)) {
            struct VTE *e = &o->vt[9];
            e->pfn((char *)o + e->d);
        } else {
            p->apo[p->c++] = o;
        }
    }
    _$_18CBinaryInputStream(&ctx, 2);
}
