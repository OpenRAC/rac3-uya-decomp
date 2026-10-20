#include "common.h"

typedef int s128 __attribute__((mode(TI)));

extern u8 *D_002211EC[];
extern u8 *func_0045E438(s32);
extern s32 func_00440848(s32);

#define U8(p, o) (*(u8 *)((p) + (o)))
#define S16(p, o) (*(s16 *)((p) + (o)))
#define S32(p, o) (*(s32 *)((p) + (o)))
#define F32(p, o) (*(f32 *)((p) + (o)))

u8 *func_00467DA8(s128 *pos, s32 id, s32 color, s32 mode, s32 b, f32 *v, s32 n, f32 sx, f32 sy, f32 z) {
    u8 *o;
    u8 *p;
    f32 *q;
    u8 t;

    o = func_0045E438(53);
    if (o != 0) {
        p = o + 32;
        *(s128 *)(o + 16) = *pos;
        F32(o, 28) = (f32)n;
        F32(o, 24) += 0.05f;
        U8(o, 3) = 72;
        S32(o, 4) = color;
        U8(o, 9) = 32;
        U8(o, 1) = 0;
        t = *D_002211EC[0];
        S16(o, 10) = id;
        U8(o, 2) = t;
        F32(o, 12) = sx * 210000.0f;
        if (mode == 0) {
            U8(o, 8) = 0;
        } else if (mode == 1) {
            U8(o, 8) = 32;
        } else {
            U8(o, 8) = func_00440848(255);
        }
        F32(p, 0) = F32(o, 12);
        S16(p, 8) = id;
        F32(p, 4) = sy * 210000.0f;
        U8(p, 10) = b;
        U8(p, 11) = color >> 24;
        F32(p, 24) = z;
        q = (f32 *)(p + 12);
        q[0] = v[0];
        q[1] = v[1];
        q[2] = v[2];
    }
    return o;
}
