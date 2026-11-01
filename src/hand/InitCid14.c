struct S { char pad[0x1C4]; char dl[0x24]; int f1e8; };
void InitCid10(struct S *p);
void InitDl__FP2DLi(void *pdl, int ib);
void InitCid14(struct S *p)
{
    InitCid10(p);
    p->f1e8 = -1;
    InitDl__FP2DLi(p->dl, 0x1D0);
}
