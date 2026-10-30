#include "m2c_prelude.h"
M2C_UNK func_0014F5A0(M2C_UNK *, f32);              /* extern */
extern M2C_UNK g_cm;

void func_0014FE28(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0x20) = 0;
    M2C_FIELD(arg0, s32 *, 0x24) = 0;
    func_0014F5A0(&g_cm, M2C_FIELD(arg0, f32 *, 0x2C));
}
