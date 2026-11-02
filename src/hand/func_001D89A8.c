/* EE (single-float EABI) stdarg, from gcc's va-mips.h */
typedef char *va_list;
#define va_start(ap, last) (ap = ((char *)__builtin_next_arg(last) - (__builtin_args_info(2) >= 8 ? 0 : (8 - __builtin_args_info(2)) * 8)))
struct MSG { int cb; int nKind; };
void *PvAllocStackImpl__FP7SWALLOC(struct MSG *pmsg);
void func_001D87C0(void *p, va_list ap, void *pv);
void *func_001D89A8(void *p, ...) {
    struct MSG msg;
    va_list ap;
    void *pv;
    va_start(ap, p);
    msg.cb = 8;
    msg.nKind = 0x10;
    pv = PvAllocStackImpl__FP7SWALLOC(&msg);
    func_001D87C0(p, ap, pv);
    return pv;
}
