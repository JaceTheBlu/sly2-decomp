/* Small helpers on 128-bit quadwords and floats, shared by the sources (phase 4).
   The quadword type has its own name (vu0_qword, same type as the sources' `qword`): many sources typedef `qword`
   themselves, and C does not allow a typedef to be repeated.  Every helper is static inline: unused ones cost
   nothing. */
#ifndef VU0_H
#define VU0_H

typedef int vu0_qword __attribute__((mode(TI)));

/* x, y, z lanes of a quadword held in a general register */
static __inline__ float GetX(vu0_qword q) { float x; __asm__("mtc1 %1,%0" : "=f"(x) : "r"(q)); return x; }
static __inline__ float GetY(vu0_qword q) { float y; __asm__("prot3w %0,%1" : "=r"(y) : "r"(q)); return y; }
static __inline__ float GetZ(vu0_qword q) { float z; __asm__("pextuw %0,$0,%1" : "=r"(z) : "r"(q)); return z; }

/* VU0 macro-mode vector arithmetic on all four lanes */
static __inline__ vu0_qword QwAdd(vu0_qword a, vu0_qword b) { vu0_qword r; __asm__("vadd.xyzw %0,%1,%2" : "=j"(r) : "j"(a), "j"(b)); return r; }
static __inline__ vu0_qword QwSub(vu0_qword a, vu0_qword b) { vu0_qword r; __asm__("vsub.xyzw %0,%1,%2" : "=j"(r) : "j"(a), "j"(b)); return r; }
/* float -> all four lanes of a VU0 register */
static __inline__ vu0_qword QwFromG(float f) { vu0_qword q; __asm__("qmtc2.ni %1,%0" : "=j"(q) : "r"(f)); return q; }

/* scalar limits */
static __inline__ float GMax(float a, float b) { return a < b ? b : a; }
static __inline__ float GMin(float a, float b) { return b < a ? b : a; }
static __inline__ int NMin(int a, int b) { return a < b ? a : b; }
static __inline__ int NMax(int a, int b) { return a < b ? b : a; }

#endif /* VU0_H */
