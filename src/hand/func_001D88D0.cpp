typedef char *va_list;
#define va_start(ap, last) (ap = ((char *)__builtin_next_arg(last) - (__builtin_args_info(2) >= 8 ? 0 : (8 - __builtin_args_info(2)) * 8)))
struct MSG { int cb; int nKind; };
struct FRAME {
    int a[4];
    FRAME();
    ~FRAME();
};
struct V { int c; void *pv; };
V *PvAllocSwImpl__Fi(MSG *pmsg);
void *PvAllocSwCopyImpl__FP7SWALLOCPv(MSG *pmsg, void *pv);
void func_001D87C0(void *p, va_list ap, V *pv);
extern "C" V *func_001D88D0(void *p, ...)
{
    FRAME frame;
    MSG msg;
    MSG *pmsg = &msg;
    va_list ap;
    V *pv;
    va_start(ap, p);
    pmsg->cb = 8;
    pmsg->nKind = 0x10;
    pv = PvAllocSwImpl__Fi(pmsg);
    func_001D87C0(p, ap, pv);
    {
        void *pvOld = pv->pv;
        pmsg->cb = pv->c * 2;
        pmsg->nKind = 0x10;
        pv->pv = PvAllocSwCopyImpl__FP7SWALLOCPv(pmsg, pvOld);
    }
    return pv;
}
