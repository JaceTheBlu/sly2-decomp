#include "m2c_prelude.h"
M2C_UNK func_00136F48(void *, M2C_UNK);             /* extern */
extern f32 g_clock;

void func_001362F8(void *arg0, s32 arg1) {
    if (arg1 != M2C_FIELD(arg0, s32 *, 0x16BC)) {
        M2C_FIELD(arg0, s32 *, 0x16BC) = arg1;
        M2C_FIELD(arg0, f32 *, 0x16C0) = (f32) g_clock;
        if (arg1 == 0) {
            func_00136F48(arg0 + 0x1710, -1);
        }
    }
}
