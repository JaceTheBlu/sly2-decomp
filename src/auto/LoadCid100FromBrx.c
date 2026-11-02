#include "m2c_prelude.h"
M2C_UNK LoadSoFromBrx__FP2SOP18CBinaryInputStream();                            /* extern */

void LoadCid100FromBrx(void *arg0) {
    void *temp_v0;

    LoadSoFromBrx__FP2SOP18CBinaryInputStream();
    temp_v0 = M2C_FIELD(arg0, void **, 0xE8);
    if (temp_v0 != NULL) {
        M2C_FIELD(temp_v0, f32 *, 0xD4) = 2.0f;
        M2C_FIELD(M2C_FIELD(arg0, void **, 0xE8), f32 *, 0xD8) = 2.0f;
    }
}
