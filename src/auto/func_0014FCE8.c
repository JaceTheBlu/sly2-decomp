#include "m2c_prelude.h"
M2C_UNK func_0014F610(M2C_UNK *, f32);              /* extern */
extern M2C_UNK g_cm;

void func_0014FCE8(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0) = 0;
    func_0014F610(&g_cm, M2C_FIELD(arg0, f32 *, 8));
    M2C_FIELD(&g_cm, f32 *, 0x24) = (f32) M2C_FIELD(arg0, f32 *, 4);
}
