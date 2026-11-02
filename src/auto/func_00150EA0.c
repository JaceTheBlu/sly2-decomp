#include "m2c_prelude.h"
M2C_UNK Reset__6CPZOOM();                            /* extern */

void func_00150EA0(void *arg0, s128 arg1, s128 arg2, f32 fparg0) {
    M2C_FIELD(arg0, s128 *, 0x80) = arg1;
    M2C_FIELD(arg0, s128 *, 0x90) = arg2;
    M2C_FIELD(arg0, f32 *, 0xA0) = fparg0;
    if (M2C_FIELD(arg0, s32 *, 0x40) == 0) {
        Reset__6CPZOOM();
    }
    M2C_FIELD(arg0, s32 *, 0x40) = 1;
}
