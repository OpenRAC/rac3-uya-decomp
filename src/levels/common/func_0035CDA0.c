#include "common.h"

typedef struct {
    s32 a;
    s32 b;
} S_35CDA0;

typedef struct {
    u8 pad0[0x10];
    u8 pos[0x14];
    s32 w24;
    s32 w28;
    s32 w2C;
} S_35CDA0o;

extern s32 D_001DD728;
extern S_35CDA0 D_001DD720[];
extern void func_004C41E8(u8 *, void *);
extern s32 func_004C73B0(s32);
extern f32 func_0040BEF8(void *, void *);
extern s32 func_0050DA08(s32);
extern void func_004C3500(S_35CDA0o *, void *, void *, s32, f32);

void func_0035CDA0(u8 *p) {
    u8 buf[16];
    S_35CDA0 tmp;
    S_35CDA0o *o;

    o = *(S_35CDA0o **)(p + 0x68);
    func_004C41E8(p + 0x10, buf);
    if (D_001DD728 >= 8) {
        return;
    }
    if (o->w2C != 0) {
        if ((u32)(func_004C73B0(o->w2C) - 1) < 2) {
            o->w28 = 0;
        } else if (o->w24 == 0) {
            o->w28 = 0;
        } else if (func_0040BEF8(o->pos, buf) <= 0.9f) {
            o->w28 = 0;
        } else {
            o->w28 = 1;
        }
    }
    tmp = D_001DD720[0];
    if (o->w24 != 0) {
        if (func_0050DA08(-1) == 0) {
            return;
        }
        if (o->w28 != 0) {
            func_004C3500(o, o->pos, 0, 0, 1.0f);
        } else {
            func_004C3500(o, o->pos, &tmp, 0, 1.0f);
        }
    }
}
