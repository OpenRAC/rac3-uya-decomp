#include "common.h"

typedef struct { u8 p0[0x20]; u8 b20; } M_00644AA0;
typedef struct {
    u8 p0[0x3E0]; M_00644AA0 *m3E0;
    u8 p3E4[0x24E8 - 0x3E4]; void *r24E8;
    u8 p24EC[0x2544 - 0x24EC]; s32 w2544; s32 w2548;
} O_00644AA0;

extern s32 D_002412AC;
extern f32 *func_005B2378(M_00644AA0 *);
extern void *func_005B9998(s32, s32, s32, void *, s32, s32, s32, f32, f32, f32, f32, f32, s32, s32, s32);

void *func_00644AA0(O_00644AA0 *o, s32 a1, s32 a2, f32 f0, f32 f1, f32 f2, f32 f3, f32 f4, s32 a3) {
    u8 buf[16];
    M_00644AA0 *m;
    f32 *v;

    if (o->w2544 % 2 != D_002412AC % 2) {
        return o->r24E8;
    }
    m = o->m3E0;
    if (m != 0 && m->b20 != 254 && m->b20 != 253) {
        v = func_005B2378(m);
        if (v != 0 && *v > 0.0f) {
            return o->m3E0;
        }
    }
    o->r24E8 = func_005B9998(a1, a2, o->w2548, buf, 0, 0, 0, f0, f1, f2, f3, f4, a3, 0, 1);
    return o->r24E8;
}
