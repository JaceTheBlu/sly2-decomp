#include "m2c_prelude.h"
M2C_UNK func_00205910(void *, M2C_UNK *, M2C_UNK, M2C_UNK *); /* extern */
M2C_UNK UpdateCid56();                            /* extern */
extern M2C_UNK D_002BD910;
extern M2C_UNK D_002BD940;

void UpdateCid64(void *arg0) {
    UpdateCid56();
    if ((M2C_FIELD(arg0, s32 *, 0xF80) == -1) && (M2C_FIELD(arg0, s32 *, 0x208) != 0)) {
        func_00205910(arg0, &D_002BD940, 3, &D_002BD910);
    }
}
