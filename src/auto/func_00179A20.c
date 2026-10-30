#include "m2c_prelude.h"
M2C_UNK func_00134320(M2C_UNK *, s32);              /* extern */
M2C_UNK func_00179598();                            /* extern */
extern M2C_UNK g_sw;

void func_00179A20(void *arg0) {
    func_00179598();
    func_00134320(&g_sw, M2C_FIELD(arg0, s32 *, 0x10));
}
