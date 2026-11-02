typedef struct LO LO;
struct LO {
    char pad[0x10];
    LO *pParent;
    char pad14[0xC];
    LO *pNextClass;
    LO *pSibling;
    int x28;
    signed char ips;
    char x2D;
    long k : 4;
    unsigned long b : 8;
    unsigned int f : 1;
    char pad30[0x34];
    LO *pChild;
    char pad68[8];
    LO *pChildEnd;
};
typedef struct ST {
    int ips;
    LO *plo;
    int f;
} ST;
typedef struct CE { LO *plo; int a, b; } CE;
extern int FIsBasicDerivedFrom__FP5BASIC3CID(LO *plo, int cid);
extern CE *func_0015E3A8(void *psw, int k);
extern int func_0015E988(int k, int cid);
extern void func_0015E3E8(void *pv, LO *plo, void *pch, unsigned int grf, LO *ctx, void *pchList, int cMax, int *pc, LO **aplo, int *pips);
int func_0015E9C8(void *psw, int grf, int cid, LO *ploCtx, int cMax, LO **aplo)
{
    volatile int unused;
    int cplo;
    int ips;
    LO *plo;
    int f;
    LO *p;
    int k;
    if (cid == -1 || (!ploCtx && (grf & 0xFF) != 5))
        return 0;
    cplo = 0;
    switch (grf & 0xFF) {
    case 3:
        f = grf & 0x200;
        for (p = ploCtx->pParent; p; p = p->pParent) {
            if (!FIsBasicDerivedFrom__FP5BASIC3CID(p, cid))
                continue;
            if ((grf & 0x100) && p->f == 0)
                continue;
            if (cplo < cMax)
                aplo[cplo] = p;
            cplo++;
        }
        break;
    case 2: {
        LO *pEnd = 0;
        if (grf & 0x100)
            pEnd = ploCtx->pChildEnd;
        f = grf & 0x200;
        for (p = ploCtx->pChild; p != pEnd; p = p->pSibling) {
            if (!FIsBasicDerivedFrom__FP5BASIC3CID(p, cid))
                continue;
            if (cplo < cMax)
                aplo[cplo] = p;
            cplo++;
        }
        break;
    }
    case 5: {
        int k = cid;
        f = grf & 0x200;
        for (; k < 199 && func_0015E988(k, cid); k++) {
            func_0015E3A8(psw, k);
            for (p = func_0015E3A8(psw, k)->plo; p; p = p->pNextClass) {
                if ((grf & 0x100) && p->f == 0)
                    continue;
                if (cplo < cMax)
                    aplo[cplo] = p;
                cplo++;
            }
        }
        break;
    }
    default:
        switch (grf & 0xFF) {
        case 1:
        case 3:
        case 4:
        case 5: {
            int i = 0;
            p = ploCtx;
            plo = p;
            f = grf & 0x200;
            for (; p; p = p->pParent)
                p->ips = ++i;
            ips = 0x7FFFFFFF;
            break;
        }
        default:
            plo = 0;
            f = grf & 0x200;
            break;
        }
        for (k = cid; k < 199 && func_0015E988(k, cid); k++) {
            func_0015E3A8(psw, k);
            for (p = func_0015E3A8(psw, k)->plo; p; p = p->pNextClass)
                func_0015E3E8(psw, p, 0, grf | 0x400, ploCtx, 0, cMax, &cplo, aplo, &ips);
        }
        for (p = plo; p; p = p->pParent)
            p->ips = 0;
        break;
    }
    if (!(grf & 0x200) && cMax < cplo)
        cplo = cMax;
    return cplo;
}
