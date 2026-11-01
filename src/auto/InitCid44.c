#include "m2c_prelude.h"
M2C_UNK InitAlo__FP3ALO();                            /* extern */
extern s128 D_002A2DA0;
extern s128 g_normalZ;

void InitCid44(void *arg0) {
    InitAlo__FP3ALO();
    M2C_FIELD(arg0, s128 *, 0x100) = (s128) D_002A2DA0;
    M2C_FIELD(arg0, s128 *, 0x110) = (s128) g_normalZ;
}
