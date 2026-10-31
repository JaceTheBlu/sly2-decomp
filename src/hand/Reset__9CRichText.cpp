#include "util.h"
struct CFont;
class CRichText {
public:
    char *m_achz;
    char *m_pchCur;
    CFont *m_pfontCur;
    CFont *m_pfontBase;
    char pad[0x150 - 0x10];
    int m_unknown;
    RGBA m_rgbaCur;
    RGBA m_rgbaSet;
    RGBA m_rgbaBase;
    void Reset();
};
void CRichText::Reset()
{
    m_pchCur = m_achz;
    m_pfontCur = m_pfontBase;
    m_rgbaSet = m_rgbaBase;
    m_rgbaCur = m_rgbaSet;
    m_unknown = 0;
}
