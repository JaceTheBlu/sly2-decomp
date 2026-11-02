#include "m2c_prelude.h"
M2C_UNK InitCid79();                            /* extern */

void InitCid80(void *arg0) {
    InitCid79();
    M2C_FIELD(arg0, s32 *, 0x264) = 1;
    M2C_FIELD(arg0, f32 *, 0x260) = 800.0f;
    M2C_FIELD(arg0, f32 *, 0x26C) = 1.0f;
}
