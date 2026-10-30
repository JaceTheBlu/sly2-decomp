#include "m2c_prelude.h"
s32 func_00132B10(s32, M2C_UNK);                    /* extern */
s32 func_0015E938(M2C_UNK *, M2C_UNK, s32, s32);    /* extern */
extern M2C_UNK g_sw;

void func_0017F408(s32 arg0, s32 arg1, void *arg2) {
    s32 temp_a2;
    s32 temp_v0;
    s32 var_s2;
    void *var_s1;

    if (arg1 > 0) {
        var_s1 = arg2;
        var_s2 = arg1;
        do {
            temp_a2 = M2C_FIELD(var_s1, s32 *, 0);
            if (temp_a2 != -1) {
                temp_v0 = func_0015E938(&g_sw, 4, temp_a2, arg0);
                if (temp_v0 != 0) {
                    if (func_00132B10(temp_v0, 0x6D) != 0) {
                        M2C_FIELD(var_s1, s32 *, 4) = temp_v0;
                    } else if (func_00132B10(temp_v0, 0x6F) != 0) {
                        M2C_FIELD(var_s1, s32 *, 8) = temp_v0;
                    }
                }
            }
            var_s2 -= 1;
            var_s1 += 0x10;
        } while (var_s2 != 0);
    }
}
