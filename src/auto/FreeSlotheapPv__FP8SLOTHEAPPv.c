#include "m2c_prelude.h"
void FreeSlotheapPv__FP8SLOTHEAPPv(void *arg0, M2C_UNK *arg1) {
    M2C_FIELD(arg0, s32 *, 0x10) = (s32) (M2C_FIELD(arg0, s32 *, 0x10) - 1);
    *arg1 = M2C_FIELD(arg0, M2C_UNK **, 0xC);
    M2C_FIELD(arg0, M2C_UNK **, 0xC) = arg1;
}
