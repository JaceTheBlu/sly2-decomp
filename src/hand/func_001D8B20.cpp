#include "cref.h"
typedef char *va_list;
#define va_start(ap, last) (ap = ((char *)__builtin_next_arg(last) - (__builtin_args_info(2) >= 8 ? 0 : (8 - __builtin_args_info(2)) * 8)))
struct FRAME {
    int a[4];
    FRAME();
    ~FRAME();
};
struct V { int c; void *pv; };
struct G;
struct H;
extern G D_003D4A60;
extern H D_003E0EA8;
void func_001D87C0(const char *p, va_list ap, V *pv);
CRef func_001D80C8(H *, V *, const CRef &, G *);
static inline CRef Eval(V *pv, const CRef &r, G *pg) { return func_001D80C8(&D_003E0EA8, pv, r, pg); }
extern "C" CRef func_001D8B20(const CRef &refArg, const char *fmt, ...)
{
    CRef ref;
    FRAME frame;
    V v;
    va_list ap;
    va_start(ap, fmt);
    func_001D87C0(fmt, ap, &v);
    ref = Eval(&v, refArg, &D_003D4A60);
    return ref;
}
