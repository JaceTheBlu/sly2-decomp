#include "m2c_prelude.h"
s32 func_00162670();                                /* extern */
M2C_UNK func_00162D50(void *);                      /* extern */
M2C_UNK func_00162F10(void *);                      /* extern */
M2C_UNK func_00165E10(M2C_UNK *, void *);           /* extern */
extern M2C_UNK g_sw;

void func_00162CD0(void *arg0, void *arg1) {
    if (func_00162670() != 0) {
        if (arg1 == M2C_FIELD(arg0, s32 *, 0x64)) {
            func_00162D50(arg0);
        }
        if (arg1 == M2C_FIELD(arg0, s32 *, 0x68)) {
            func_00162F10(arg0);
        }
        if (M2C_FIELD(arg1, s32 *, 0xB8) != -1) {
            func_00165E10(&g_sw, arg1);
        }
    }
}
