#include "common.h"

/* localdecomp:start func_00325F68 */
typedef struct { u8 p0[0x86]; s16 h86; } P_00325F68;
typedef struct { u8 p0[0x14]; f32 f14; u8 p18[0x50 - 0x18]; P_00325F68 *p50; } S_00325F68;
typedef struct { u8 p0[0x70]; s32 w70; } A_00325F68;

extern S_00325F68 D_001E2AC0[];
extern u8 D_001A4C60[];
extern s32 func_00453210(void *, s32);
extern void func_003E6D50(s32, s32, f32, f32);
extern void func_003E6DA8(s32, f32, f32);
extern void func_003E6DF0(s32, s32, f32, f32);

void func_00325F68(void *a0, A_00325F68 *a1) {
    S_00325F68 *s = &D_001E2AC0[0];
    f32 t;
    f32 k;

    if (s->p50->h86 != 0) {
        return;
    }
    if (a1->w70 != -1 && func_00453210(D_001A4C60, a1->w70) != 0) {
        return;
    }
    k = 0.003f;
    func_003E6D50(0, 0, 8.0f, k);
    func_003E6DA8(0, 4.0f, k);
    if (s->f14 < 0.15f) {
        t = (s->f14 - 0.15f) / -0.3f;
        if (t > 1.0f) {
            t = 1.0f;
        } else if (t < 0.0f) {
            t = 0.0f;
        }
        func_003E6DF0(0, 0, t * -1.5f + 2.5f, 0.005f);
    } else {
        func_003E6DF0(0, 0, 2.5f, 0.005f);
    }
}
/* localdecomp:end func_00325F68 */
