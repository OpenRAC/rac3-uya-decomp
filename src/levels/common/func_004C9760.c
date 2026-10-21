#include "common.h"

/* localdecomp:start func_004C9760 */
typedef struct { f32 x, y; } V2_A6520;
typedef struct { V2_A6520 *f0; V2_A6520 *f4; u8 p8[4]; s32 *fC; f32 *f10; u8 p14[0x14]; s32 f28; u8 p2C[4]; s32 f30; u8 p34[4]; s32 f38; s32 f3C; } O_A6520;
extern s32 func_004C9728_A6520();
extern long func_00401CD0(s32);

extern void func_00410590_A6520(f32, f32, f32, s32, s32, s32, s32, s32);
void func_004C9760(O_A6520 *o) {
    s32 t;
    f32 x;
    V2_A6520 *p0;
    V2_A6520 *p4;
    s32 a;
    if (*o->f10 != 0.0f && o->f38 != 0) {
        t = func_004C9728_A6520(o);
        x = o->f0->x;
        switch (o->f3C) {
        case 0:
            break;
        case 1:
            x -= (f32)(t >> 1);
            break;
        case 2:
            x -= (f32)t;
            break;
        }
        a = *o->fC;
        p0 = o->f0;
        p4 = o->f4;
        func_00410590_A6520(x, p0->y, p4->x, a, o->f38, t, ((s32 (*)(s32))func_00401CD0)(o->f30), o->f28);
    }
}
/* localdecomp:end func_004C9760 */
