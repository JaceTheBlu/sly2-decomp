#include "m2c_prelude.h"
M2C_UNK SetTimerTimers__FP5TIMER6TIMERS(s32, M2C_UNK); /* extern */
s32 func_0015E938(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
extern M2C_UNK g_sw;

void func_001A3020(s32 *arg0) {
    s32 temp_v0;

    temp_v0 = func_0015E938(&g_sw, 0x405, 0x373, 0);
    *arg0 = temp_v0;
    if (temp_v0 != 0) {
        SetTimerTimers__FP5TIMER6TIMERS(temp_v0, 1);
    }
}
