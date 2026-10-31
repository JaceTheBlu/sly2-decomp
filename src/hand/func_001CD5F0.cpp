#include "util.h"
#include "gifs.h"
extern "C" void func_001CD5F0(struct RGBA*,GIFS*,float,float,float,float);
void func_001CD5F0(struct RGBA *pc, GIFS *pgs, float x0, float y0, float x1, float y1)
{
    pgs->AddPrimPack( pc->bAlpha <= 0xFE ? 0x46 : 6, 5, 0x441EE);
    pc->bAlpha = (pc->bAlpha + 1) >> 1;
    pgs->PackAD( 0x47, 0x31001);
    pgs->PackAD( 0x42, 0x44);
    pgs->PackRGBA( *(int *)pc);
    pgs->PackXYZF( (int)((x0 * 0.8f + 1792.0f) * 16.0f), (int)((y0 * 0.45454547f + 1936.0f) * 16.0f), 0, 0);
    pgs->PackXYZF( (int)((x1 * 0.8f + 1792.0f) * 16.0f), (int)((y1 * 0.45454547f + 1936.0f) * 16.0f), 0, 0);
}
