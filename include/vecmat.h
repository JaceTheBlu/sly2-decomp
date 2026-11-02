/* VU0 register wrappers (Sly 1: splice/vecmat.h): a float in all four lanes, a vector in a VU0 register. */
#ifndef VECMAT_H
#define VECMAT_H
#include "vu0.h"

struct VU_FLOAT { vu0_qword q; };
struct VU_VECTOR { vu0_qword q; };

#ifndef __cplusplus
typedef struct VU_FLOAT VU_FLOAT;
typedef struct VU_VECTOR VU_VECTOR;
#endif

#endif /* VECMAT_H */
