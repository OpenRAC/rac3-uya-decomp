#include "common.h"

/* localdecomp:start func_004C8FC0 */
typedef struct { f32 x, y; } V2_3A5DF0;
typedef struct { V2_3A5DF0 *f0; V2_3A5DF0 *f4; u8 p8[4]; s32 *fC; f32 *f10; u8 p14[0x18]; f32 *f2C; u8 p30[4]; s32 f34; } O_3A5DF0;
extern void func_004C7F48(s32, s32, f32, f32, f32, f32, f32);
extern f32 D_001E1228[];
extern s32 D_001E1220_003A5DF0[];
void func_004C8FC0(O_3A5DF0 *o) {
    f32 zero = 0.0f;
    if (*o->f10 != zero && o->f34 != 0) {
        f32 z0 = zero, z1 = zero;
        f32 x = o->f0->x + zero;
        f32 y = o->f0->y + zero;
        s32 fl = *o->fC;
        func_004C7F48(o->f34, fl, x, y, o->f4->x, o->f4->y * D_001E1228[0] + (D_001E1220_003A5DF0[0] == 1 ? z0 : z1), *o->f2C);
    }
}
/* localdecomp:end func_004C8FC0 */
