#include "cref.h"
extern "C" {
CRef func_001249A8(int k, void *a, void *b, void *c);
CRef func_00124F80(void *a, void *b, void *c);
}
CRef func_00124F80(void *a, void *b, void *c)
{
    CRef ref;
    ref = func_001249A8(0x7C, a, b, c);
    return ref;
}
