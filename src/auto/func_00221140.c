#include "m2c_prelude.h"
s32 PloCloneLo(s32, s32);                        /* extern */
M2C_UNK func_002311B0();                            /* extern */

void func_00221140(void *arg0) {
    func_002311B0();
    M2C_FIELD(arg0, s32 *, 0x10C) = PloCloneLo(M2C_FIELD(arg0, s32 *, 0x10C), M2C_FIELD(arg0, s32 *, 0x10));
}
