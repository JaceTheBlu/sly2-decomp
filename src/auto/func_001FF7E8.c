#include "m2c_prelude.h"
s32 func_00256DD0();                                /* extern */
M2C_UNK __as__3SPXP1X(void *, s32);                 /* extern */
M2C_UNK func_00259A88(s32);                         /* extern */

void func_001FF7E8(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0x3A14) = 1;
    __as__3SPXP1X(arg0, func_00256DD0());
    func_00259A88(M2C_FIELD(arg0, s32 *, 0));
}
