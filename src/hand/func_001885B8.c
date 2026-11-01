typedef struct { float x, y, z; } VEC3;
struct S { char pad[0x240]; VEC3 v; };
extern char D_002BE990[];
void LoadCid56FromBrx(struct S *p);
void func_001A64E8(struct S *p, int n, void *pv);
void func_001885B8(struct S *p)
{
    VEC3 *pv;
    LoadCid56FromBrx(p);
    pv = &p->v;
    pv->x = 0.0f;
    pv->y = 0.0f;
    pv->z = -75.0f;
    func_001A64E8(p, 0xAD, D_002BE990);
}
