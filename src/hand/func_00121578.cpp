struct NODE;
struct CRef {
    int m_tagk; union { int n; float g; void *pv; } u;
    CRef() { m_tagk = -1; }
    CRef(const CRef &r);
    void Decref();
    void InitTag(int tagk);
    ~CRef() { Decref(); }
    CRef &operator=(const CRef &r);
    CRef &operator=(NODE *pn);
    void SetTag(int tagk) { Decref(); InitTag(tagk); }
};
extern char D_004520A8[];
extern "C" {
void FreeSlotheapPv__FP8SLOTHEAPPv(void *pheap, void *pv);
void func_002550F8(void *pv);
NODE *func_00256B48();
}
struct SPM {
    NODE *p;
    ~SPM();
    void operator=(NODE *pn);
};
struct NODE {
    int cref;
    int x4;
    CRef ref;
    SPM pnext;
    void SetNext(NODE *pn) { pnext = pn; }
    void operator delete(void *pv) { func_002550F8(pv); FreeSlotheapPv__FP8SLOTHEAPPv(D_004520A8, pv); }
};
struct SPN {
    NODE *p;
    void Set(NODE *pn);
    SPN() {}
    SPN(NODE *pn) { Set(pn); }
    SPN(const SPN &);
    ~SPN() { NODE *pn = p; if (pn && --pn->cref == 0) delete pn; }
    NODE *operator->() { return p; }
};
extern "C" SPN func_00121578(CRef **ppref1, CRef **ppref2);
SPN func_00121578(CRef **ppref1, CRef **ppref2)
{
    SPN sp;
    sp.Set(func_00256B48());
    sp->ref = func_00256B48();
    NODE *pn1 = (NODE *)sp->ref.u.pv;
    CRef *pref1 = &pn1->ref;
    *pref1 = func_00256B48();
    pn1->SetNext(func_00256B48());
    NODE *pn2 = (NODE *)pref1->u.pv;
    pn2->ref.SetTag(0x12);
    pn2->SetNext(func_00256B48());
    *ppref1 = &pn2->pnext.p->ref;
    CRef *pref2 = &pn1->pnext.p->ref;
    *pref2 = func_00256B48();
    NODE *pn3 = (NODE *)pref2->u.pv;
    pn3->ref.SetTag(0x12);
    pn3->SetNext(func_00256B48());
    *ppref2 = &pn3->pnext.p->ref;
    return SPN(sp.p);
}
