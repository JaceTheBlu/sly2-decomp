#include "m2c_prelude.h"
s32 func_0015E938(M2C_UNK *, M2C_UNK, s32, void *); /* extern */
M2C_UNK func_00183F50();                            /* extern */
extern M2C_UNK g_sw;

void func_001842B0(void *arg0) {
    func_00183F50();
    M2C_FIELD(arg0, s32 *, 0x188) = func_0015E938(&g_sw, 4, M2C_FIELD(arg0, s32 *, 0x184), arg0);
    M2C_FIELD(arg0, s32 *, 0x190) = func_0015E938(&g_sw, 4, M2C_FIELD(arg0, s32 *, 0x18C), arg0);
    M2C_FIELD(arg0, s32 *, 0x198) = func_0015E938(&g_sw, 4, M2C_FIELD(arg0, s32 *, 0x194), arg0);
}
