struct P { char pad[0x40]; int fl; char pad2[0x17C - 0x44]; void *px; };
void *__builtin_new(int cb);
void *func_001E81C0(void *pv, struct P *p);
void func_001E6180(struct P *p);
void func_001A6CA8(struct P *p, int n);
void *func_001E7840(struct P *p, int f)
{
    if (!p->px) {
        p->px = func_001E81C0(__builtin_new(0x90), p);
        func_001E6180(p);
        func_001A6CA8(p, 0);
        { int v = p->fl; if ((v ^ 1) & 1) *(int *)v &= ~0x20; else p->fl = v & ~0x20; }
        { int v = p->fl; if ((v ^ 1) & 1) *(int *)v |= 0xC; else p->fl = v | 0xC; }
    } else if (f == 1) {
        func_001A6CA8(p, 0);
        { int v = p->fl; if ((v ^ 1) & 1) *(int *)v |= 0x4; else p->fl = v | 0x4; }
    }
    return p->px;
}
