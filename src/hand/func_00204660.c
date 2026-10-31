typedef int qword __attribute__((mode(TI)));
typedef struct MATRIX3 { qword a[3]; } MATRIX3;
extern qword g_normalZ;
MATRIX3 LoadRotateMatrixRad__FfUx(qword v, float g);
struct S { char pad[0x1A8]; float g; int pad2; MATRIX3 m; };
void func_00204660(struct S *p, float g) { p->g = g; p->m = LoadRotateMatrixRad__FfUx(g_normalZ, g); }
