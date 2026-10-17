#include "common.h"

typedef struct { s32 w0; s32 w4; f32 f8; s32 wC; void *w10; } P_3D7F00;
typedef struct { u8 p0[0x3F0]; P_3D7F00 p; u8 pad[0x460 - 0x3F0 - 0x14]; } E_3D7F00;
extern E_3D7F00 D_001E2540[];
extern void func_003D7F48(void);

void func_003D7F00(s32 i) {
    E_3D7F00 *e = &D_001E2540[i];
    P_3D7F00 *p = &e->p;
    p->w4 = 0;
    e->p.w0 = 0;
    p->f8 = 10000.0f;
    p->wC = 0;
    p->w10 = func_003D7F48;
}
