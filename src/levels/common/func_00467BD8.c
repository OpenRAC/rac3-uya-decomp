#include "common.h"

/* localdecomp:start func_00467BD8 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_467BD8;
typedef struct {
    f32 f0;
    f32 f4;
    s32 f8;
    s32 fC;
    f32 f10;
} Sub_467BD8;
typedef struct {
    u8 b0;
    u8 b1;
    u8 b2;
    u8 b3;
    s32 f4;
    u8 b8;
    u8 b9;
    s16 hA;
    f32 fC;
    V4_467BD8 pos;
    Sub_467BD8 sub;
} Obj_467BD8;
typedef struct {
    u8 b0;
} E_467BD8;
extern E_467BD8 *D_002211E8[];
extern Obj_467BD8 *func_0045E438(s32);
extern u8 func_00440848(s32);
Obj_467BD8 *func_00467BD8(V4_467BD8 *pos, s32 a, s32 b, s32 c, f32 x, f32 y) {
    Obj_467BD8 *o;
    Sub_467BD8 *q;
    o = func_0045E438(0x34);
    if (o != 0) {
        o->pos = *pos;
        o->b3 = 0x44;
        o->f4 = a;
        o->b9 = 0x22;
        o->b1 = 1;
        o->pos.z += 0.05f;
        o->b2 = D_002211E8[0]->b0;
        o->fC = x * 210000.0f;
        o->hA = c;
        q = &o->sub;
        o->b8 = func_00440848(0xFF);
        q->f8 = a;
        q->fC = b;
        q->f0 = x;
        q->f4 = y;
        q->f10 = 1.0f / (f32)c;
    }
    return o;
}
/* localdecomp:end func_00467BD8 */
