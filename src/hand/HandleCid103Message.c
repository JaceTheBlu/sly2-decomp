struct S { char pad[0x184]; int st; int f188; int f18c; };
void func_00133590(struct S *, int, int);
void func_0013C560(struct S *, int);
void HandleCid103Message(struct S *p, int msg, int a) {
    func_00133590(p, msg, a);
    switch (msg) {
    case 4:
        if (p->st == 5) func_0013C560(p, 0);
        break;
    case 8:
        if (a == p->f18c) {
            switch (p->st) {
            case 2: func_0013C560(p, 4); break;
            case 3: func_0013C560(p, 1); break;
            }
        }
        break;
    }
}
