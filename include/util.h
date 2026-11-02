/* Small value types shared by most of the engine (Sly 1: util.h, common.h). */
#ifndef UTIL_H
#define UTIL_H

struct LM               /* limits */
{
    float gMin, gMax;
};

struct RGBA
{
    unsigned char bRed, bGreen, bBlue, bAlpha;
};

#ifndef __cplusplus
typedef struct LM LM;
typedef struct RGBA RGBA;
#endif

#endif /* UTIL_H */
