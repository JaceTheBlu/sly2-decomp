#include "m2c_prelude.h"
M2C_UNK SignalSema(s32);                            /* extern */

void LeaveCritSect__FP8CRITSECT(void *arg0) {
    s32 temp_v0;

    temp_v0 = M2C_FIELD(arg0, s32 *, 0) - 1;
    M2C_FIELD(arg0, s32 *, 0) = temp_v0;
    if (temp_v0 == 0) {
        M2C_FIELD(arg0, s32 *, 4) = -1;
        SignalSema(M2C_FIELD(arg0, s32 *, 8));
    }
}
