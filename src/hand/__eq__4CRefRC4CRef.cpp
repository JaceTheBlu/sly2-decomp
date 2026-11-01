#include "vec.h"
struct VECTOR2 { float x, y; };
extern "C" int func_00233178(const void *a, const void *b, int cb);
struct CRef {
    int m_tagk;
    union { int n; void *pv; VECTOR *pvec; VECTOR2 *pvec2; } u;
    bool operator==(const CRef &ref);
};
bool CRef::operator==(const CRef &ref)
{
    if (m_tagk != ref.m_tagk)
        return false;
    switch (m_tagk) {
    case 0x15: case 0x16: case 0x17: case 0x18: case 0x19:
    case 0x1F: case 0x20: case 0x21: case 0x22: case 0x23:
        return u.n == ref.u.n;
    case 0x1B:
        return func_00233178(u.pv, ref.u.pv, 0x40) == 0;
    case 0x1D:
        return u.pvec2->x == ref.u.pvec2->x && u.pvec2->y == ref.u.pvec2->y;
    case 0x1A: case 0x1C: case 0x1E:
        return u.pvec->x == ref.u.pvec->x && u.pvec->y == ref.u.pvec->y && u.pvec->z == ref.u.pvec->z;
    }
    return true;
}
