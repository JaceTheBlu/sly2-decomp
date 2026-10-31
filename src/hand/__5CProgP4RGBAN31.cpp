#include "util.h"
class CProg {
public:
    int m_cRetry; int m_nRemain; int m_nTarget; int m_nMax; char m_fActive; char pad[0x3f]; int m_n50;
    RGBA m_rgba0, m_rgba1, m_rgba2, m_rgba3;
    CProg(RGBA *p0, RGBA *p1, RGBA *p2, RGBA *p3);
    void Begin() { m_cRetry = 0; m_n50 = 0; m_nMax = 0; m_nTarget = 0; m_nRemain = 0; m_fActive = 0; }
};
CProg::CProg(RGBA *p0, RGBA *p1, RGBA *p2, RGBA *p3)
{
    m_rgba0 = *p0; m_rgba1 = *p1; m_rgba2 = *p2; m_rgba3 = *p3;
    Begin();
}
