#include "common.h"

/* localdecomp:start func_0046B488 */
typedef struct {
    u8 pad0[4];
    s32 w4;
    u8 pad8[2];
    s16 h;
    f32 f0C;
    f32 f10;
    f32 f14;
    f32 f18;
    u8 pad1C[4];
    s32 w20;
} O_46B488;
extern s32 func_0040BAC0(void *);
extern void func_0045E580(void *);
extern s32 func_0040D020(f32, s32, s32);

void func_0046B488(O_46B488 *o) {
    if (o->f10 < 2.0f || 1021.0f < o->f10 || o->f14 < 2.0f || 1021.0f < o->f14 ||
        o->f18 < 2.0f || 1021.0f < o->f18 || func_0040BAC0(&o->h) != 0) {
        func_0045E580(o);
        return;
    }
    if (o->w20 != 0) {
        o->f0C = o->f0C * 0.99f;
        o->w4 = func_0040D020((f32)(o->h - 1) / (f32)o->h, 0x30FFFFFF, o->w4);
    } else {
        o->f0C = o->f0C * 0.95f;
        o->w4 = func_0040D020((f32)(o->h - 1) / (f32)o->h, 0x603F1008, o->w4);
    }
}
/* localdecomp:end func_0046B488 */
