/* Game clock (P2/clock).  One instance, g_clock, advanced once per frame by MarkClockTick. */
#ifndef CLOCK_H
#define CLOCK_H

typedef unsigned long TICK;     /* EE cycle count, 64-bit (long is 64-bit with ee-gcc) */

struct CLOCK
{
    float t;            /* 0x00 game time: advances by dt, stops while paused */
    float dt;           /* 0x04 game time step of the current frame */
    float rt;           /* 0x08 rate applied to dt */
    float rtReal;       /* 0x0C rate applied to dtReal */
    float dtReal;       /* 0x10 time step that ignores pause and the game rate */
    float tReal;        /* 0x14 sum of dtReal */
    float art[9];       /* 0x18 rates by kind (SetClockRate); art[3] scales dtFrame and dt */
    float tFrame;       /* 0x3C time that ignores pause */
    float dtFrame;      /* 0x40 frame step, clamped to [1/60, 1/30] s and scaled by art[3] */
    TICK tickFrame;     /* 0x48 tick of the current frame */
    TICK tickRaw;       /* 0x50 last raw COUNT register value (TickNow) */
    int cWrap;          /* 0x58 COUNT register wrap-arounds */
};

extern struct CLOCK g_clock;   /* global variables are not mangled by g++ 2.95: no extern "C" needed */

#endif /* CLOCK_H */
