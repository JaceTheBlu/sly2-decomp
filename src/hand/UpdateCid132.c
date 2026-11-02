struct S { char pad[0xB0]; int fb0; int fb4; void *fb8; void *fbc; void *fc0; int fc4; char pad2[0xCC - 0xC8]; void *fcc; };
void UpdateLo(struct S *p);
int func_002121E8(void *p, int n);
void func_00162F60(struct S *p);
void func_00162FD0(struct S *p);
void func_00163170(struct S *p, int n);
void UpdateCid132(struct S *p)
{
    UpdateLo(p);
    switch (p->fc4) {
    case 1:
        if (!func_002121E8(p->fb8, p->fb0)) {
            func_00162F60(p);
            if (p->fc0 || p->fcc)
                func_00163170(p, 3);
            else
                func_00163170(p, 2);
        }
        break;
    case 2:
        if (!func_002121E8(p->fb8, p->fb4)) {
            func_00162FD0(p);
            func_00163170(p, 0);
        }
        break;
    case 3:
        if (!func_002121E8(p->fbc, 0x30F))
            func_00162FD0(p);
        break;
    }
}
