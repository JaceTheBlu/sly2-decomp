#include "m2c_prelude.h"
void *__builtin_new(M2C_UNK);                       /* extern */
M2C_UNK func_00212158(void *);                      /* extern */
extern M2C_UNK D_002DAA50;

void *func_00112C50(void) {
    void *temp_v0;

    temp_v0 = __builtin_new(0x110);
    func_00212158(temp_v0);
    M2C_FIELD(temp_v0, M2C_UNK **, 0xC) = &D_002DAA50;
    return temp_v0;
}
