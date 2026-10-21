#include "common.h"

/* localdecomp:start func_00495B08 */
extern s32 func_004950C8(void *, s32, s32);
extern s32 func_004950E8(s32, s32);
extern void func_00495B08(void *);
extern s32 func_00512480(s32, f32, f32);

typedef struct {
    u8 p0[0x10]; s32 f10; s32 f14; u8 p18[8]; f32 f20[12];
    f32 f50; f32 f54; f32 f58; f32 f5C; u8 p60[0x10]; f32 f70; u8 p74[4]; f32 f78; u8 p7C[0x20]; u32 f9C;
} S_3B52B0;
void func_00495B08(void *arg0) {
    S_3B52B0 *o = arg0;
    s32 i;
    s32 j;
    u32 k;
    f32 y;
    for (i = 0; i < o->f14; i++) {
        y = o->f50 + o->f58 - o->f54;
        for (j = 0; j < o->f10 + 2; j++) {
            func_00512480(func_004950C8(o, i, j), o->f20[i], y + o->f54 * j - o->f78);
        }
        if (i == 0) {
            for (k = 0; k < o->f9C; k++) {
                func_00512480(func_004950E8((s32)o, k), o->f5C, y + (f32)(k - 1) * o->f54 + o->f70);
            }
        }
    }
}
/* localdecomp:end func_00495B08 */
