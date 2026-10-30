#include "m2c_prelude.h"
M2C_UNK func_0014AE38(void *, M2C_UNK);             /* extern */
M2C_UNK func_001EEF78();                            /* extern */
M2C_UNK func_001FEEA0(M2C_UNK *);                   /* extern */
M2C_UNK func_00209970(void *, M2C_UNK);             /* extern */
extern M2C_UNK g_sndmgr;

void func_0014A248(void *arg0) {
    func_001EEF78();
    func_0014AE38(arg0, -1);
    func_00209970(M2C_FIELD(arg0, void **, 0x10), 0x24);
    func_001FEEA0(&g_sndmgr);
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x10), s32 *, 0x4A4) = 1;
}
