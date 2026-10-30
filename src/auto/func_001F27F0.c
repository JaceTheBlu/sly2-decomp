#include "m2c_prelude.h"
M2C_UNK func_00134320(M2C_UNK *, void *);           /* extern */
void *func_001F2798();                              /* extern */
extern M2C_UNK g_sw;

void func_001F27F0(void *arg0) {
    void *temp_v0;
    void *temp_v1;

    if (M2C_FIELD(arg0, s32 *, 0xEC) == 0) {
        temp_v0 = func_001F2798();
        if (M2C_FIELD(temp_v0, s32 *, 0xEC) == 0) {
            temp_v1 = M2C_FIELD(temp_v0, void **, 0xC);
            M2C_FIELD(temp_v0, s32 *, 0xEC) = M2C_FIELD(temp_v1, s32 (**)(void *), 0x1AC)(temp_v0 + M2C_FIELD(temp_v1, s16 *, 0x1A8));
            func_00134320(&g_sw, temp_v0);
        }
        M2C_FIELD(arg0, s32 *, 0xEC) = M2C_FIELD(temp_v0, s32 *, 0xEC);
    }
}
