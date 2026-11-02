#include "m2c_prelude.h"
extern f32 g_clock;

void func_00227440(void *arg0, s32 arg1) {
    if (arg1 != M2C_FIELD(arg0, s32 *, 0x110)) {
        M2C_FIELD(arg0, s32 *, 0x110) = arg1;
        M2C_FIELD(arg0, f32 *, 0x114) = (f32) g_clock;
    }
}
