#include "m2c_prelude.h"
s32 *func_001FD028(M2C_UNK *, s32);                 /* extern */
extern M2C_UNK g_sndmgr;

s32 func_001FBC20(void *arg0) {
    s32 *temp_v0;
    s32 var_v1;

    temp_v0 = func_001FD028(&g_sndmgr, M2C_FIELD(arg0, s32 *, 0x60));
    var_v1 = -1;
    if (temp_v0 != NULL) {
        var_v1 = *temp_v0;
    }
    return var_v1;
}
