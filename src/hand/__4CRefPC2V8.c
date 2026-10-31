typedef struct CLQ { int a, b; } CLQ;
typedef struct CRef { int m_tagk; void *m_p; } CRef;
typedef struct LR { CLQ v; int cref; } LR;
extern char D_004521D0[];
LR *func_0011CCC0(void *pslotheap);
CRef *__4CRefPC2V8(CRef *pref, CLQ *pv)
{
    LR *p;
    pref->m_tagk = 0x1D;
    p = func_0011CCC0(D_004521D0);
    p->cref = 0;
    pref->m_p = p;
    p->cref++;
    ((LR *)pref->m_p)->v = *pv;
    return pref;
}
