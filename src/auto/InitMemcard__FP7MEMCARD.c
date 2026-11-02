#include "m2c_prelude.h"
s32 SemaCreate__Fii(M2C_UNK, M2C_UNK);              /* extern */

void InitMemcard__FP7MEMCARD(void *arg0) {
    s32 temp_v0;

    temp_v0 = SemaCreate__Fii(1, 1);
    M2C_FIELD(arg0, s32 *, 0) = temp_v0;
    M2C_FIELD(arg0, s32 *, 4) = -1;
    M2C_FIELD(arg0, s32 *, 0x10) = 0x20;
}
