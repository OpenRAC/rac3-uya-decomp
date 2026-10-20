#include "common.h"

typedef struct {
    u8 pad0[16];
    f32 v16[2];
    f32 z;
    u8 pad1c[0x43 - 0x1C];
    u8 b67;
    u8 pad44[4];
    f32 f72;
} A_457E08;

typedef struct {
    u8 pad0[8];
    f32 f8;
    f32 f12;
    f32 f16;
    u8 pad14[40 - 20];
    f32 f40;
    u8 pad2c[52 - 44];
    f32 f52;
    s32 flags56;
    u8 pad3c[80 - 60];
    f32 v80[2];
    f32 f88;
    u8 pad5c[144 - 92];
    f32 f144;
    u32 f148;
    u8 pad98[156 - 152];
    s32 f156;
    u8 padA0[168 - 160];
    f32 f168;
    u8 padAC[176 - 172];
    f32 f176;
    f32 f180;
    u8 padB8[192 - 184];
    s16 h192;
    s16 h194;
    u8 padC4[204 - 196];
    f32 f204;
    f32 f208;
    f32 f212;
    s32 i216;
    u8 padDC[230 - 220];
    u8 b230;
    u8 b231;
    u8 b232;
    u8 b233;
    u8 b234;
} B_457E08;

typedef struct {
    u8 pad[73];
    u8 b73;
    u16 h74;
} C_457E08;

extern void func_004583C0(A_457E08 *, B_457E08 *, f32);
extern f32 func_0040BF68(f32 *);
extern f32 func_0040C490(f32, f32);
extern C_457E08 *func_00445EB8(A_457E08 *);
extern void func_004585E8(A_457E08 *, B_457E08 *);
extern f32 func_0040BFB0(f32 *, s32);
extern f32 func_0040BFE8(f32 *, s32);
extern s32 func_00459DA8(A_457E08 *);
extern void func_00441C78(A_457E08 *, s32, s32, s32);
extern s32 func_00459E50(A_457E08 *, B_457E08 *);
extern void func_00443A90(A_457E08 *, s32, s32, f32 *, f32);

void func_00457E08(A_457E08 *a, B_457E08 *b, s32 c) {
    s32 r;
    C_457E08 *p;
    f32 s;

    func_004583C0(a, b, 0.0f);
    r = 0;
    if (a->z < b->f144 - b->f8) {
        b->f148 |= 2;
        r = 1;
    }
    if (((*(u8 *)&b->flags56 ^ 1) & 1) && b->h194 < 5 && b->f144 + b->f12 < a->z) {
        b->f148 |= 1;
        r = 1;
    }
    if (b->h192 != 0) {
        if (b->f16 < func_0040C490(b->f88, func_0040BF68(b->v80))) {
            b->f148 |= 4;
            r = 1;
        }
    }
    if (b->i216 != -1 && b->h192 != 0) {
        p = func_00445EB8(a);
        if (p != 0 && p->b73 != 0 && p->h74 != 0 && ((p->h74 >> b->i216) & 1)) {
            b->f148 |= 0x200;
            r = 1;
        }
    }
    if (r) {
        func_004585E8(a, b);
        func_004583C0(a, b, 0.0f);
    }
    if (a->z <= b->f144) {
        if (b->f144 <= a->z - b->f168) {
            a->z = b->f144;
        }
        b->h194 = 0;
        b->h192++;
    } else {
        b->h192 = 0;
        b->h194++;
    }
    if (b->flags56 & 0x400) {
        b->f204 = func_0040BFB0(a->v16, c);
    } else {
        b->f204 = func_0040BFE8(a->v16, c);
    }
    if (b->f204 <= b->f52) {
        b->f148 |= 0x80;
    }
    if (b->f156 & 1) {
        if (func_00459DA8(a)) {
            b->f156 &= ~1;
        } else {
            b->f148 |= 0x100;
        }
    }
    if (b->flags56 & 0x80) {
        if (a->b67 == b->b232 || a->b67 == b->b233) {
            if (b->f208 != 0.0f) {
                s = b->f208;
            } else {
                s = b->f40;
            }
            s = b->f176 / s;
            a->f72 = s;
            if (b->f212 < s) {
                a->f72 = b->f212;
            } else if (s < 1.0f / b->f212) {
                a->f72 = 1.0f / b->f212;
            }
        }
    }
    if (b->flags56 & 0x40) {
        if ((b->f156 & 2) && b->f180 != 0.0f) {
            s32 t = a->b67;
            if ((u8)t == b->b232 || (u8)t == b->b233) {
                b->b234 = t;
                func_00441C78(a, (0.0f < b->f180) ? b->b230 : b->b231, 0, 10);
            }
        } else if ((a->b67 == b->b230 || a->b67 == b->b231) && b->b234 != 255) {
            func_00441C78(a, b->b234, 0, 10);
        }
    }
    if ((b->flags56 & 0x200) && func_00459E50(a, b)) {
        func_00443A90(a, 0, 0x10000, a->v16, 255.0f);
    }
}
