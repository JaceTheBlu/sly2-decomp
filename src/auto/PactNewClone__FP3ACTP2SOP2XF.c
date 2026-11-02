#include "m2c_prelude.h"
void *func_0012E238(s32);                           /* extern */

void *PactNewClone__FP3ACTP2SOP2XF(s32 *arg0, s32 arg1, s32 arg2) {
    void *temp_v0;
    void *temp_v1;

    temp_v0 = func_0012E238(*arg0);
    temp_v1 = M2C_FIELD(temp_v0, void **, 0x18);
    M2C_FIELD(temp_v1, M2C_UNK (**)(void *, s32 *, s32, s32), 0x34)(temp_v0 + M2C_FIELD(temp_v1, s16 *, 0x30), arg0, arg1, arg2);
    return temp_v0;
}
