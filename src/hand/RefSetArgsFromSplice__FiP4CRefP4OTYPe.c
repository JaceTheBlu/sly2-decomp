#include "cref.h"
/* EE (single-float EABI) stdarg, from gcc's va-mips.h */
typedef char *va_list;
#define va_start(ap, last) (ap = ((char *)__builtin_next_arg(last) - (__builtin_args_info(2) >= 8 ? 0 : (8 - __builtin_args_info(2)) * 8)))
struct CRef *RefSetPvsFromSplice__FiP4CRefP4OTYPPPv(struct CRef *ret, int c, struct CRef *aref, int *aotype, int *an);
struct CRef *RefSetArgsFromSplice__FiP4CRefP4OTYPe(struct CRef *ret, int c, struct CRef *aref, int *aotype, ...)
{
    va_list ap;
    int an[32];
    int i;
    va_start(ap, aotype);
    for (i = 0; i < c; i++) {
        ap += 8;
        an[i] = *(int *)(ap - 8);
    }
    RefSetPvsFromSplice__FiP4CRefP4OTYPPPv(ret, c, aref, aotype, an);
    return ret;
}
