#include "m2c_prelude.h"
M2C_UNK func_001A6CA8(void *, M2C_UNK);             /* extern */
M2C_UNK InitAlo__FP3ALO();                            /* extern */

void func_0021D278(void *arg0) {
    InitAlo__FP3ALO();
    func_001A6CA8(arg0, 3);
    M2C_FIELD(arg0, s32 *, 0xE8) = 0x17E;
    M2C_FIELD(arg0, f32 *, 0xEC) = 25.0f;
    M2C_FIELD(arg0, s32 *, 0xF4) = -1;
}
