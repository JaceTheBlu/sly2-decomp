#include "m2c_prelude.h"
M2C_UNK InitCid48();                            /* extern */

void func_0021BB88(void *arg0) {
    void *temp_v0;

    InitCid48();
    temp_v0 = arg0 + 0x170;
    M2C_FIELD(arg0, f32 *, 0x170) = 1.0f;
    M2C_FIELD(temp_v0, s32 *, 4) = 0;
    M2C_FIELD(temp_v0, s32 *, 8) = 0;
    M2C_FIELD(arg0, f32 *, 0x184) = 100.0f;
}
