#include "util.h"
class CRichText {
public:
    char pad[0x154];
    RGBA m_rgbaCur;
    int pad158;
    RGBA m_rgbaBase;
    void SetBaseColor(RGBA *rgba);
};
void CRichText::SetBaseColor(RGBA *rgba)
{
    m_rgbaBase = *rgba;
    m_rgbaCur = m_rgbaBase;
}
