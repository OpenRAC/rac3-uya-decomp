#include "common.h"

typedef struct {
    f32 v[4];
} __attribute__((aligned(16))) Vec4;

typedef struct {
    u8 b0;
    u8 b1;
    u8 b2;
    u8 b3;
    u32 w4;
    u8 b8;
    u8 b9;
    s16 hA;
    f32 fC;
    Vec4 q10;
    Vec4 q20;
} Part_44A168;

extern u8 *D_0021F0BC[];
extern Part_44A168 *func_0043DA98(s32);
extern f32 func_00420D30(f32, f32);

void func_0044A168(Vec4 *pos, s32 type, Vec4 dir, f32 scale) {
    Part_44A168 *p;
    f32 size;
    s32 alpha;

    p = func_0043DA98(73);
    if (p == 0) {
        return;
    }
    size = 0.0f;
    alpha = 0;
    switch (type) {
    case 0:
        size = 0.12f;
        func_00420D30(0.25f, 0.25f);
        alpha = 32;
        break;
    case 1:
        size = 0.5f;
        func_00420D30(1.0f, 1.0f);
        alpha = 13;
        break;
    }
    p->hA = 55;
    p->w4 = (alpha << 24) | 0xFFFFFF;
    p->b9 = 36;
    p->b3 = 72;
    p->b1 = 0;
    p->b2 = D_0021F0BC[0][type];
    p->fC = size * 210000.0f;
    p->b8 = (s32)func_00420D30(0.0f, 360.0f);
    p->q10 = *pos;
    p->q20 = dir;
    p->q20.v[3] = scale;
}
