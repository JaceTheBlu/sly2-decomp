#include "m2c_prelude.h"
s128 CalcCmAdjust__FP2CMP2SOP6CPDEFIP6VECTOR();                               /* extern */

void func_0014E920(void *arg0) {
    void *temp_v0;
    void *temp_v1;

    M2C_FIELD(arg0, s128 *, 0x2C0) = CalcCmAdjust__FP2CMP2SOP6CPDEFIP6VECTOR();
    temp_v1 = arg0 + 0x2F0;
    temp_v0 = arg0 + 0x2D0;
    M2C_FIELD(temp_v0, s32 *, 8) = 0;
    M2C_FIELD(temp_v0, s32 *, 4) = 0;
    M2C_FIELD(arg0, s32 *, 0x2D0) = 0;
    M2C_FIELD(temp_v1, s32 *, 8) = 0;
    M2C_FIELD(temp_v1, s32 *, 4) = 0;
    M2C_FIELD(arg0, s32 *, 0x2F0) = 0;
}
