#include "m2c_prelude.h"
M2C_UNK func_00141640(void *, s32 *);               /* extern */
M2C_UNK func_0019EA00(void *, s32 *);               /* extern */
extern f32 g_clock;

void func_001358A8(void *arg0, s32 *arg1) {
    s32 temp_v1;
    s32 temp_v1_2;

    temp_v1 = M2C_FIELD(arg0, s32 *, 0x13D0);
    if (temp_v1 != 0) {
        if ((temp_v1 != 9) && (M2C_FIELD(arg0, s32 *, 0x4CC) != 0)) {
            M2C_FIELD(arg0, f32 *, 0x1080) = (f32) g_clock;
        }
    }
    func_00141640(arg0, arg1);
    temp_v1_2 = M2C_FIELD(arg0, s32 *, 0x13D0);
    switch (temp_v1_2) {                            /* irregular */
    case 13:
        func_0019EA00(arg0 + 0xF50, arg1);
        return;
    case 5:
        *arg1 |= 1;
        return;
    }
}
