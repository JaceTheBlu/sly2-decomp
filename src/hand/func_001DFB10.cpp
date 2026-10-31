struct MSG { int cb; int nKind; };
struct FRAME {
    int a[4];
    FRAME();
    ~FRAME();
};
struct ENT { char a[0x50]; };
struct OBJ {
    char pad[0x50];
    int c;
    ENT *ae;
    int cMax;
    char pad5c[0x7C - 0x5C];
    int f7C;
};
void *PvAllocStackImpl__FP7SWALLOC(MSG *);
void *PvAllocSwImpl__Fi(MSG *);
void func_001AE5A0(void *, void *, int);
void func_001E0290(OBJ *, int);
void func_001A5C28(OBJ *, void *);
static inline int Max(int a, int b) { return a < b ? b : a; }
extern "C" void func_001DFB10(OBJ *p, void *x)
{
    FRAME frame;
    MSG msg;
    MSG *pmsg = &msg;
    pmsg->cb = 0xA000;
    pmsg->nKind = 0x10;
    p->ae = (ENT *)PvAllocStackImpl__FP7SWALLOC(pmsg);
    func_001E0290(p, -1);
    p->f7C = 1;
    func_001A5C28(p, x);
    {
        ENT *aeOld = p->ae;
        p->cMax = Max(p->c, p->cMax) + 1;
        pmsg->cb = p->cMax * sizeof(ENT);
        pmsg->nKind = 0x10;
        p->ae = (ENT *)PvAllocSwImpl__Fi(pmsg);
        func_001AE5A0(p->ae, aeOld, p->c * sizeof(ENT));
    }
}
