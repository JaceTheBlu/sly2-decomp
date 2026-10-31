typedef struct CRef { int m_tagk; int m_tag; } CRef;
void Decref__4CRef(CRef *pref);
CRef *__4CRefRC4CRef(CRef *pref, CRef *prefSrc);
void __as__4CRefPv(CRef *pref, void *p);
extern char D_003DA0C0[];
CRef *func_00125690(CRef *ret)
{
    CRef ref;
    ref.m_tagk = -1;
    __as__4CRefPv(&ref, D_003DA0C0);
    __4CRefRC4CRef(ret, &ref);
    Decref__4CRef(&ref);
    return ret;
}
