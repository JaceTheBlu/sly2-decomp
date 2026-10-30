#include "m2c_prelude.h"
M2C_UNK func_0020EFC0(M2C_UNK *, M2C_UNK);          /* extern */
M2C_UNK func_0020F030(M2C_UNK *, M2C_UNK);          /* extern */
extern f32 D_002DDED0;
extern M2C_UNK g_sw;

void func_00153128(void *arg0, s32 arg1) {
    s32 temp_v0;

    temp_v0 = M2C_FIELD(arg0, s32 *, 0x50);
    if (temp_v0 != arg1) {
        if (temp_v0 == 1) {
            func_0020F030(&g_sw, 3);
        }
        M2C_FIELD(arg0, s32 *, 0x50) = arg1;
        M2C_FIELD(arg0, f32 *, 0x54) = (f32) D_002DDED0;
        M2C_FIELD(arg0, s32 *, 0x1C0) = 0;
        if (arg1 == 1) {
            func_0020EFC0(&g_sw, 3);
        }
    }
}
