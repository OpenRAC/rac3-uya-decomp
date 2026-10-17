#include "common.h"

extern s32 func_005148E8(s32, s32, s32, f32, f32, f32, f32);
extern s32 func_00512AB0(s32, s32, s32);
extern s32 func_005149B8(s32, s32, s32, f32, f32, f32, f32, f32, f32);
extern s32 func_00512738(s32, f32, f32);
extern s32 func_00512AB0();
s32 func_00512AB0(s32, s32, s32);

extern s32 func_005148E8(s32, s32, s32, f32, f32, f32, f32);
extern s32 func_00512738(s32, f32, f32);
s32 func_005149B8(s32 a, s32 b, s32 c, f32 d, f32 e, f32 f, f32 g, f32 h, f32 i) {
    s32 r;
    s32 t;
    s32 u;
    u = func_005148E8(a, b, c, d, e, f, g);
    r = func_00512738(a, h, i) != 0;
    if (u == 0) r = 0;
    t = ((s32 (*)(s32, s32, s32))func_00512AB0)(a, 0x40, 1) != 0;
    return r & t;
}
