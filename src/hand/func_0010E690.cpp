#include "cref.h"
typedef int qword __attribute__((mode(TI)));
extern "C" CRef func_00201360(int c, void *aref, int *ak, ...);
extern "C" { void func_001F8AD8(void *p, int a, int b, void *ps); CRef func_0010E690(void *p, int c, void *aref); }
struct BIG { qword aq[4]; };
CRef func_0010E690(void *p, int c, void *aref)
{
    int ak[3] = {0x100D, 5, 4};
    BIG s;
    int a, b;
    CRef ref = func_00201360(3, aref, ak, &a, &b, &s);
    ref.Decref();
    ref.InitTag(0x24);
    func_001F8AD8(p, a, b, &s);
    return ref;
}
