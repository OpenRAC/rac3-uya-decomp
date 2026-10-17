#include "common.h"

typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) Vec4;

typedef struct {
    f32 unk00;
    f32 unk04;
    s32 unk08;
    f32 unk0C;
    f32 unk10;
    s32 unk14;
} S_467288_Sub;

typedef struct {
    u8 unk00;
    u8 unk01;
    u8 unk02;
    u8 unk03;
    s32 unk04;
    u8 unk08;
    u8 unk09;
    s16 unk0A;
    f32 unk0C;
    Vec4 unk10;
    S_467288_Sub sub;
} S_467288;

extern u8 *D_002211CC[];
extern S_467288 *func_0045E438(s32 size);
extern s32 func_00440848(s32);
extern s32 func_0013D3E0(void);
extern f32 func_00440978(void);
extern f32 func_004408C0(f32, f32);
extern f32 func_0040C3C8(f32);
extern f32 func_0040C3E0(f32);

S_467288 *func_00467288(Vec4 *a0, s32 a1, s32 a2, f32 f12, f32 f13) {
    S_467288 *p = func_0045E438(45);
    if (p != 0) {
        S_467288_Sub *q;
        f32 ang;
        f32 r;
        s32 c;

        p->unk10 = *a0;
        if (a2 == -1) {
            c = ((func_00440848(6) + 20) << 24) | 0x808080;
        } else {
            c = a2;
        }
        p->unk04 = c;
        p->unk09 = 33;
        p->unk03 = 72;
        p->unk01 = 1;
        q = &p->sub;
        p->unk02 = *D_002211CC[0];
        p->unk08 = func_0013D3E0();
        p->unk0A = 4;
        p->unk0C = f12 * 210000.0f;
        ang = func_00440978();
        r = func_004408C0(0.0015f, 0.0025f);
        p->sub.unk00 = func_0040C3C8(ang) * r;
        q->unk04 = func_0040C3E0(ang) * r;
        q->unk14 = a1;
        q->unk10 = f13;
        q->unk08 = 0;
    }
    return p;
}
