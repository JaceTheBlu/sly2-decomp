#include "vu0.h"
void func_00218790(unsigned char *pa, unsigned char *pb, unsigned char *pc, unsigned char *pd,
                   unsigned char *pout0, unsigned char *pout1)
{
    int i;
    for (i = 0; i < 4; i++) {
        float x = GMax(GMin((float)(pa[i] - 127) * 0.007874016f, 1.0f), -1.0f);
        float y = GMax(GMin((float)(pc[i] - 127) * 0.007874016f, 1.0f), -1.0f);
        float e = (float)pb[i] - 127.0f;
        float d = (float)pd[i] - 127.0f;
        pout0[i] = (int)(GMax(GMin(x * y, 1.0f), -1.0f) * 127.0f + 128.0f);
        pout1[i] = (int)(GMax(GMin(x * d + e, 128.0f), -127.0f) + 127.0f);
    }
}
