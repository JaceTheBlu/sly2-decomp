struct R { int cref; int f4; int ref8[2]; int f10; };
struct N { int f0; int f4; struct R *pr; int id; struct N *pnext; };
struct S { char pad[0x39f0]; struct N *pfirst; int f39f4; int f39f8; int pool39fc; };
extern char D_004520A8[];
void func_0011A118(void *, struct N *);
void func_00256D40(void *, int);
void func_00129EC8(void *);
void func_002550F8(struct R *);
void FreeSlotheapPv__FP8SLOTHEAPPv(void *, void *);
void func_00133130(struct S *p, int id) {
    struct N *pn;
    if (id == -1) return;
    for (pn = p->pfirst; pn; pn = pn->pnext) {
        if (pn->id == id) {
            struct R *pr;
            func_0011A118(&p->pfirst, pn);
            pr = pn->pr;
            if (--pr->cref == 0 && pr) {
                func_00256D40(&pr->f10, 2);
                func_00129EC8(pr->ref8);
                func_002550F8(pr);
                FreeSlotheapPv__FP8SLOTHEAPPv(D_004520A8, pr);
            }
            FreeSlotheapPv__FP8SLOTHEAPPv(&p->pool39fc, pn);
            return;
        }
    }
}
