typedef struct CB { int a; int b; } CB;
typedef struct E { float x; float y; int n; } E;
typedef struct T { char pad[0xB0]; E *pe; } T;
E *PvAllocSwImpl__Fi(CB *pcb);
void func_0012FDE8(T *t, int n, float x, float y)
{
    CB cb;
    E *pe;
    cb.a = 0xC;
    cb.b = 0x10;
    pe = PvAllocSwImpl__Fi(&cb);
    t->pe = pe;
    pe->x = x;
    pe->y = y;
    pe->n = n;
}
