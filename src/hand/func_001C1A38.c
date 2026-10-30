/* Insert a begin event (g0, kind 1) and an end event (g1, kind 0) into a time-sorted array of 8-byte events.  The memmove goes through an inline helper: its parameters get their own pseudos, which gives the
   target's "pointer copied into a0/a1, then a0 += 16" argument setup. */
struct E { float t; unsigned short k; unsigned short bit; };
void *func_002332B8(void *dst, const void *src, unsigned int cb);
static inline void Move(void *pvDst, void *pvSrc, unsigned cb) { func_002332B8(pvDst, pvSrc, cb); }
void func_001C1A38(int c, struct E *ae, int bit, float g0, float g1)
{
    int i, j;
    for (i = 0; i < c; i++)
        if (g0 <= ae[i].t) break;
    for (j = i; j < c; j++)
        if (g1 < ae[j].t) break;
    Move(&ae[j + 2], &ae[j], (c - j) * 8U);
    ae[j + 1].t = g1;
    ae[j + 1].k = 0;
    ae[j + 1].bit = bit;
    Move(&ae[i + 1], &ae[i], (j - i) * 8U);
    ae[i].bit = bit;
    ae[i].t = g0;
    ae[i].k = 1;
}
