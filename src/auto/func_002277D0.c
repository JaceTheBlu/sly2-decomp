#include "m2c_prelude.h"
s32 func_0013E368(M2C_UNK *, s32);                  /* extern */
M2C_UNK strcpy(s8 *, s32);                          /* extern */
extern M2C_UNK g_sw;

void func_002277D0(s32 *arg0, s8 *arg1) {
    s32 temp_v1;

    temp_v1 = *arg0;
    if (temp_v1 == -1) {
        *arg1 = 0;
        return;
    }
    strcpy(arg1, func_0013E368(&g_sw, temp_v1));
}
