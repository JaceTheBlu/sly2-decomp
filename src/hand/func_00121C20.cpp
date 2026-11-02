struct CRef {
    int m_tagk; union { int n; float g; void *pv; } u;
    CRef() { m_tagk = -1; }
    CRef(int tagk) { InitTag(tagk); }
    CRef(const CRef &r);
    CRef(struct NODE *p);
    void Decref();
    void InitTag(int tagk);
    ~CRef() { Decref(); }
    CRef &operator=(const CRef &r);
    CRef &operator=(float g);
};
struct NODE;
extern char D_004520A8[];
extern "C" {
void FreeSlotheapPv__FP8SLOTHEAPPv(void *pheap, void *pv);
void func_002550F8(void *pv);
NODE *func_00256B48();
}
struct SPM {
    NODE *p;
    ~SPM();
    SPM &operator=(NODE *pn);
};
struct NODE {
    int cref;
    int x4;
    CRef ref;
    SPM pnext;
    void operator delete(void *pv) { func_002550F8(pv); FreeSlotheapPv__FP8SLOTHEAPPv(D_004520A8, pv); }
};
struct SPN {
    NODE *p;
    void Set(NODE *pn);
    ~SPN() { NODE *pn = p; if (pn && --pn->cref == 0) delete pn; }
    NODE *operator->() { return p; }
};
extern "C" void func_00121578(SPN *psp, CRef **ppa, CRef **ppb);
extern "C" CRef func_00127838(NODE *pn, CRef *aref);
extern "C" CRef func_00121C20(void *pbasic, CRef *aref, CRef *arefCall);
CRef func_00121C20(void *pbasic, CRef *aref, CRef *arefCall)
{
    if (aref[1].m_tagk == 0x1F) {
        SPN sp;
        CRef *pa;
        CRef *pb;
        NODE *pn;
        func_00121578(&sp, &pa, &pb);
        *pa = aref[0];
        pn = (NODE *)aref[1].u.pv;
        while (pn) {
            *pb = pn->ref;
            CRef ref = func_00127838(sp.p, arefCall);
            pn = pn->pnext.p;
        }
    }
    return CRef(0x24);
}
