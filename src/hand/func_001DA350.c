extern struct CLOCK { float t; float dt; } g_clock;
typedef struct { char pad[0x58]; int x58; } W;
typedef struct {
    char pad[0x10];
    int state;
    float t;
    int x18;
    float x1C;
    int x20;
    float x24;
    W *pw;
} OBJ;
void func_001DA5C8(OBJ *, int);
int func_002132D0(W *);
int func_002121E8(W *, int);
void func_001DA350(OBJ *p)
{
    if (p->pw == 0)
        return;
    switch (p->state) {
    case 0:
        break;
    case 1:
        if (p->pw->x58 == 2)
            func_001DA5C8(p, 2);
        break;
    case 2:
        if (p->x20 != -1) {
            func_001DA5C8(p, 4);
        } else if (p->x1C == 0.0f) {
            func_001DA5C8(p, 3);
        } else if (0.0f < p->x1C) {
            if (p->pw && !func_002132D0(p->pw))
                p->t += g_clock.dt;
        }
        break;
    case 3:
        if (p->pw->x58 < 2)
            func_001DA5C8(p, 0);
        break;
    case 4:
        if (func_002121E8(p->pw, 0x312))
            break;
        if (p->x20 == -1)
            func_001DA5C8(p, 0);
        else
            func_001DA5C8(p, 2);
        break;
    }
}
