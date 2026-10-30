struct BIS {
    int grf; char pad[0x2C];
    void *vt;       /* 0x30 */
    int cbSpool;    /* 0x34 */
    char *abSpool;  /* 0x38 */
    int x3c, x40, x44, x48, x4c, x50, x54, x58, x5c, x60;
};
extern char D_002D2918[];
void __18CBinaryInputStream(struct BIS *p);
struct BIS *func_001848A8(struct BIS *p, int cb, char *pv, int grf)
{
    char *ab;
    __18CBinaryInputStream(p);
    ab = (char *)(((int)pv + 0x3F) & ~0x3F);
    p->vt = D_002D2918;
    p->grf = grf;
    p->cbSpool = ((int)pv + cb - (int)ab) & ~0x3F;
    p->x50 = -1;
    p->x3c = -1;
    p->abSpool = ab;
    p->x40 = p->x44 = p->x48 = p->x4c = p->x54 = p->x58 = p->x5c = p->x60 = 0;
    return p;
}
