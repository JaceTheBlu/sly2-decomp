/* Event bitset sweep: walk ae[] backward/forward from i toward time g, toggling grf bits of events whose kind==f. */
struct E { float t; unsigned short k; unsigned short bit; };
int func_001C14A8(struct E *ae, int i, float g, unsigned int *grf, int f)
{
    if (g <= ae[i].t) {
        for (;;) {
            struct E *pe = &ae[i];
            if (pe->t < g) break;
            if (pe->k == f) {
                unsigned int bit = pe->bit;
                unsigned int w = bit / 32;
                unsigned int b = bit - w * 32;
                if (!f) *(unsigned int *)((int)grf + (w << 2)) |= 1U << b;
                else *(unsigned int *)((int)grf + (w << 2)) -= 1U << b;
            }
            i--;
        }
    } else {
        i++;
        for (;;) {
            struct E *pe = &ae[i];
            if (g < pe->t) break;
            if (pe->k == f) {
                unsigned int bit = pe->bit;
                unsigned int w = bit / 32;
                unsigned int b = bit - w * 32;
                if (f) *(unsigned int *)((int)grf + (w << 2)) |= 1U << b;
                else *(unsigned int *)((int)grf + (w << 2)) -= 1U << b;
            }
            i++;
        }
        i--;
    }
    return i;
}
