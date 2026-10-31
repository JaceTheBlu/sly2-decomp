#include "m2c_prelude.h"
M2C_UNK Reset__6CPZOOM();                            /* extern */

void func_00150E20(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0x10) = arg1;
    if (M2C_FIELD(arg0, s32 *, 0x40) != 0) {
        Reset__6CPZOOM();
    }
    M2C_FIELD(arg0, s32 *, 0x40) = 0;
}
