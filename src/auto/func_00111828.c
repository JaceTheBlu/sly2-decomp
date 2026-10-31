#include "m2c_prelude.h"
void *__builtin_new(M2C_UNK);                       /* extern */
M2C_UNK func_00256360(void *);                      /* extern */
extern M2C_UNK D_002CDE40;

void *func_00111828(void) {
    void *temp_v0;

    temp_v0 = __builtin_new(0x1020);
    func_00256360(temp_v0);
    M2C_FIELD(temp_v0, M2C_UNK **, 0xC) = &D_002CDE40;
    return temp_v0;
}
