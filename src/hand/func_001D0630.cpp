#include "mat.h"
typedef int qword __attribute__((mode(TI)));
union U { qword q; float f; };
struct G { char pad[0x60]; MATRIX3 mat; };
struct SPIN { char pad[0x40]; qword axis; };
struct S {char pad[0x14];float start,duration;char pad1C[0x40-0x1C];MATRIX3 mat;char pad70[0xF0-0x70];SPIN *spin;char padF4[0x100-0xF4];qword pos;};
extern G g_cm;
extern struct CLOCK {float t,dt;} g_clock;
extern "C" {
qword func_0014F268(G*,qword);
MATRIX3 CalculateDmat__FP7MATRIX3T0(const MATRIX3&,const MATRIX3&);
void func_0011BCF8(MATRIX3*,float*,qword*);
MATRIX3 LoadRotateMatrixRad__FfUx(qword,float);
int func_001CF338(S*,qword,const MATRIX3&);
void func_001D0630(S*);
}
static inline MATRIX3 Mul(const MATRIX3 &a,const MATRIX3 &b) return r {
 __asm__("vmulax.xyz $ACC,%1,%4x\n\tvmadday.xyz $ACC,%2,%4y\n\tvmaddz.xyz %0,%3,%4z":"=j"(r.r[0]):"j"(a.r[0]),"j"(a.r[1]),"j"(a.r[2]),"j"(b.r[0]));
 __asm__("vmulax.xyz $ACC,%1,%4x\n\tvmadday.xyz $ACC,%2,%4y\n\tvmaddz.xyz %0,%3,%4z":"=j"(r.r[1]):"j"(a.r[0]),"j"(a.r[1]),"j"(a.r[2]),"j"(b.r[1]));
 __asm__("vmulax.xyz $ACC,%1,%4x\n\tvmadday.xyz $ACC,%2,%4y\n\tvmaddz.xyz %0,%3,%4z":"=j"(r.r[2]):"j"(a.r[0]),"j"(a.r[1]),"j"(a.r[2]),"j"(b.r[2]));
}
void func_001D0630(S *p) {
 MATRIX3 camera,fade,spin,render;
 U axis;float angle;
 G *pg=&g_cm;
 qword view=func_0014F268(pg,p->pos);
 camera=CalculateDmat__FP7MATRIX3T0(p->mat,pg->mat);
 func_0011BCF8(&camera,&angle,&axis.q);
 float t=(g_clock.t-p->start)/p->duration;
 fade=LoadRotateMatrixRad__FfUx(axis.q,angle*t);
 spin=LoadRotateMatrixRad__FfUx(p->spin->axis,(t+t)*3.14159274f);
 render=Mul(Mul(fade,spin),p->mat);
 func_001CF338(p,view,render);
}
