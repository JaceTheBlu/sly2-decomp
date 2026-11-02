typedef struct Q { char pad[0x10]; struct Q *next; } Q;
typedef struct P { char pad[0x2C]; int f; int pad2; Q *pq; char pad3[8]; struct P *next; } P;
extern P *D_003E159C;
void MeasureCrvl__FP4CRVL(Q *q);
void func_001EE7B0(void)
{
    P *p;
    Q *q;
    int unused[4];
    for (p = D_003E159C; p; p = p->next) {
        if (p->f) {
            p->f = 0;
            for (q = p->pq; q; q = q->next) MeasureCrvl__FP4CRVL(q);
        }
    }
}
