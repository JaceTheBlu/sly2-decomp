typedef int TI __attribute__((mode(TI)));
typedef struct CRef { int m_tagk; void *m_p; } CRef;
typedef struct VR { TI vec; int cref; } VR;
extern char D_004521B8[];
VR *func_0011CCC0(void *pslotheap);
void Decref__4CRef(CRef *pref);
CRef *SetClq__4CRefP3CLQ(CRef *pref, TI *pvec)
{
    VR *p;
    Decref__4CRef(pref);
    pref->m_tagk = 0x1C;
    p = func_0011CCC0(D_004521B8);
    p->cref = 0;
    pref->m_p = p;
    p->cref++;
    ((VR *)pref->m_p)->vec = *pvec;
    return pref;
}
