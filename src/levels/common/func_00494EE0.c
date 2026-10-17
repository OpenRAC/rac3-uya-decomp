#include "common.h"

extern s32 func_00494EE0();

typedef struct { s32 f0; s32 f4; s32 f8; s32 fC; s32 f10; s32 f14; f32 f18; f32 f1C; f32 f20; f32 a24[4]; f32 a34[4]; f32 a44[4]; } S_3B4788;
typedef struct { u8 f0; u8 p1[3]; s32 f4; s32 f8; s32 fC; s32 f10; s32 f14; s32 f18; s32 f1C; f32 a20[4]; f32 a30[4]; f32 a40[4]; f32 f50; f32 f54; s32 f58; u8 p5C[0x4C]; u8 fA8; u8 fA9; u8 pAA[2]; f32 fAC; s32 fB0; } O_3B4788;
extern void func_004951B8();
extern void func_0040BBA8();
extern void func_00495630();
s32 func_00494EE0(O_3B4788 *o, S_3B4788 *s) {
    s32 size;
    s32 ret = 1;
    s32 i, j, k;
    o->fA8 = 0;
    o->fA9 = 0;
    { s32 t = s->fC * 0x44; size = s->f14 * t; }
    if (size >= s->f0) {
        ret = 0;
    } else {
        o->f4 = 0;
        o->f8 = 0;
        o->fC = s->fC;
        o->f10 = s->f10;
        o->f14 = s->f14;
        o->f18 = s->f8;
        o->f1C = 0;
        for (k = 0; k < 4; k++) {
            o->a20[k] = s->a24[k];
            o->a30[k] = s->a44[k];
            o->a40[k] = s->a34[k];
        }
        o->f50 = s->f1C;
        o->f54 = s->f20;
        o->fAC = s->f18;
        o->fB0 = s->f4;
        func_004951B8(o);
        o->f0 = 1;
    }
    func_0040BBA8(o->fB0, 0, size);
    for (i = 0; i < o->f14; i++) {
        for (j = 0; j < o->fC; j++) {
            *(s32 *)((u8 *)func_004950A8(o, i, j) + 0x40) = 0;
        }
    }
    func_00495630(o, 0x8066CCFF, 0x80808080, 0x666690CC, 0x80FFFFFF);
    o->f58 = 0;
    return ret;
}
