#include "m2c_prelude.h"
M2C_UNK func_00181EB0(s32, void *, M2C_UNK);        /* extern */
extern f32 D_002BE884;
extern f32 g_clock;

void func_00181E10(s32 arg0, void *arg1) {
    s32 temp_s1;

    do {
        temp_s1 = M2C_FIELD(arg1, s32 *, 0x24);
        if ((temp_s1 == 1) && ((g_clock - M2C_FIELD(arg1, f32 *, 0x28)) > D_002BE884)) {
            func_00181EB0(arg0, arg1, 0);
        }
    } while (M2C_FIELD(arg1, s32 *, 0x24) != temp_s1);
}
