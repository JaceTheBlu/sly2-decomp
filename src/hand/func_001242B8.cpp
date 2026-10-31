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
    CRef &operator=(NODE *p);
    CRef &operator=(struct LO *p);
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
    void operator=(NODE *pn);
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
    int pad[3];
};
struct LO;
struct SW { char pad[0x3C]; int n3C; };
struct OW { char pad[0xC]; SW *psw; };
struct G { char pad[0x3F0C]; int n3F0C; };
extern G g_sw;
extern "C" LO *PloFindSwNearest__FP2SW3OIDP2LO(G *pg, int kind, int n, void *pv, int n2);
extern "C" CRef func_001242B8(void *pbasic, CRef *aref);
CRef func_001242B8(void *pbasic, CRef *aref) { CRef res; if (aref[0].m_tagk == 0) return aref[0];
 void *pv = aref[1].u.pv; SW *psw; if (aref[2].m_tagk != 0) psw = ((OW *)aref[2].u.pv)->psw; else psw = (SW *)pv;
 SPN spRes; NODE *pnR = func_00256B48(); spRes.Set(pnR);
 NODE *pTail; NODE *pn = (NODE *)aref[0].u.pv; while (pn) { SPN spNew; NODE *pnNew = func_00256B48(); spNew.Set(pnNew);
   int n = pn->ref.u.n; spNew->ref = PloFindSwNearest__FP2SW3OIDP2LO(&g_sw, pv ? 1 : 5, n, pv, psw ? psw->n3C : g_sw.n3F0C);
   if (spRes->ref.m_tagk != 0x1F) spRes->ref = spNew.p; else pTail->pnext = spNew.p;
   NODE *p = spNew.p; pn = pn->pnext.p; pTail = p; } int unused[4]; res = CRef((NODE *)spRes->ref.u.pv); return res; }
