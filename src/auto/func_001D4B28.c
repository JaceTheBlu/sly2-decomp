#include "m2c_prelude.h"
extern f32 g_clock;

void func_001D4B28(void *arg0, s32 arg1) {
    if (arg1 != M2C_FIELD(arg0, s32 *, 0x188)) {
        M2C_FIELD(arg0, s32 *, 0x188) = arg1;
        M2C_FIELD(arg0, f32 *, 0x18C) = (f32) g_clock;
    }
}
