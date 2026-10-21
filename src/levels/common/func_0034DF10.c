#include "common.h"

/* localdecomp:start func_0034DF10 */
typedef struct { f32 x, y, z, w; } E_34DF10;
typedef struct { E_34DF10 *p0; E_34DF10 *p4; s32 x8; s32 xC; s32 x10; s32 x14; u8 pad18[4]; s16 x1C; } V_34DF10;
typedef struct { u8 pad[0x68]; V_34DF10 *x68; } O_34DF10;
void func_0034DF10(O_34DF10 *a0) {
    V_34DF10 *v = a0->x68;
    s32 i;
    for (i = 0; i < 10; i++) {
        v->p0[i].x = 0.0f;
        v->p0[i].y = 0.0f;
        v->p0[i].z = 0.0f;
        v->p0[i].w = 1.0f;
    }
    for (i = 0; i < 20; i++) {
        v->p4[i].x = 0.0f;
        v->p4[i].y = 0.0f;
        v->p4[i].z = 0.0f;
        v->p4[i].w = 1.0f;
    }
    v->x8 = 0;
    v->xC = 0;
    v->x10 = 0;
    v->x14 = 0;
    v->x1C = 6;
}
/* localdecomp:end func_0034DF10 */
