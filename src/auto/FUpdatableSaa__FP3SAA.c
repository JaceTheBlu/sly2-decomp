#include "m2c_prelude.h"
extern f32 g_clock;

s32 FUpdatableSaa__FP3SAA(void *arg0) {
    if (M2C_FIELD(arg0, f32 *, 0x10) != g_clock) {
        M2C_FIELD(arg0, f32 *, 0x10) = (f32) g_clock;
        return 1;
    }
    return 0;
}
