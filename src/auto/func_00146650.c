#include "m2c_prelude.h"
M2C_UNK func_001EEFC0(void *);                      /* extern */
M2C_UNK func_001EF038();                            /* extern */
extern f32 g_clock;

void func_00146650(void *arg0, s32 arg1) {
    s32 temp_v0;

    temp_v0 = M2C_FIELD(arg0, s32 *, 0x30);
    if (arg1 != temp_v0) {
        if (temp_v0 == 2) {
            func_001EF038();
        }
        M2C_FIELD(arg0, s32 *, 0x30) = arg1;
        M2C_FIELD(arg0, f32 *, 0x34) = (f32) g_clock;
        if (arg1 == 2) {
            func_001EEFC0(arg0);
        }
    }
}
