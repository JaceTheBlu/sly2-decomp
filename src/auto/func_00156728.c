#include "m2c_prelude.h"
M2C_UNK func_00156780();                            /* extern */
extern f32 g_clock;

void func_00156728(void *arg0) {
    f32 temp_f2;

    temp_f2 = M2C_FIELD(M2C_FIELD(arg0, void **, 0x14), f32 *, 0x60);
    if (temp_f2 >= 0.0f) {
        if ((M2C_FIELD(arg0, f32 *, 0x4C) + temp_f2) < g_clock) {
            func_00156780();
        }
    }
}
