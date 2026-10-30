#include "m2c_prelude.h"
M2C_UNK func_0014D8C0(M2C_UNK *);                   /* extern */
M2C_UNK func_0014FCE8(void *, s32, void *);         /* extern */
extern M2C_UNK g_cm;

void func_0012E7F0(void *arg0, s32 arg1, void *arg2) {
    if (M2C_FIELD(arg0, s32 *, 0x10) == arg2) {
        if (M2C_FIELD(arg2, s32 *, 0x120) != 0) {
            func_0014D8C0(&g_cm);
        }
        M2C_FIELD(arg0, s32 *, 0x10) = 0;
    }
    func_0014FCE8(arg0, arg1, arg2);
}
