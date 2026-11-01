#include "m2c_prelude.h"
s32 PloCloneLo(s32, s32);                        /* extern */
M2C_UNK CloneAlo__FP3ALOT0();                            /* extern */

void func_00221140(void *arg0) {
    CloneAlo__FP3ALOT0();
    M2C_FIELD(arg0, s32 *, 0x10C) = PloCloneLo(M2C_FIELD(arg0, s32 *, 0x10C), M2C_FIELD(arg0, s32 *, 0x10));
}
