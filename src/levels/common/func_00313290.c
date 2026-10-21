#include "common.h"

/* localdecomp:start func_00313290 */
typedef struct {
    u8 pad0[52];
    f32 f52;
    u8 pad1[16];
    f32 f72;
    u8 pad2[20];
    s32 f96;
    u8 pad3[4];
    s32 f104;
    u8 pad4[4];
    s32 f112;
    u8 pad5[8];
    s32 f124;
} S_313290;
extern S_313290 *D_001E17B4;
extern void func_00313400(S_313290 *a0, f32 f12, s32 a1, s32 a2, f32 f13, s32 a3, f32 f14, s32 t0);
void func_00313290(s32 a0) {
    s32 i;
    for (i = 0; i < 320; i++) {
        S_313290 *e = (S_313290 *)((u32)(i * 128) + (u32)D_001E17B4);
        if (e->f124 == a0) {
            func_00313400(e, e->f72, e->f104, e->f96, e->f52, 46, 0.25f, e->f112);
        }
    }
}
/* localdecomp:end func_00313290 */
