typedef union QW { unsigned int aun[4]; unsigned short aus[8]; } QW;
typedef struct ALLOCREQ { int cb; int nKind; } ALLOCREQ;
struct X { int pad[4]; int cqw; };
struct Y { int pad[4]; QW *aqw; char *pb; };
QW *PvAllocSwCopyImpl__FP7SWALLOCPv(ALLOCREQ *preq, QW *aqw);
void func_00169EB8(struct X *px, struct Y *py, int cqw, QW *aqwSrc, int fReloc, int nNew, int nOld)
{
    ALLOCREQ req;
    QW *aqw;
    req.cb = cqw << 4;
    req.nKind = 0x10;
    px->cqw = cqw;
    aqw = PvAllocSwCopyImpl__FP7SWALLOCPv(&req, aqwSrc);
    py->aqw = aqw;
    py->pb += (char *)aqw - (char *)aqwSrc;
    if (fReloc) {
        int dn = nNew - nOld;
        QW *pqw = aqw;
        while (pqw < py->aqw + px->cqw) {
            switch ((int)(pqw->aun[0] >> 28)) {
            case 4:
                pqw->aun[1] += dn;
                pqw++;
                break;
            case 1:
                pqw += pqw->aus[0] + 1;
                break;
            case 6:
                pqw = py->aqw + px->cqw;
                break;
            }
        }
    }
}
