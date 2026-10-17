#include "common.h"

typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) Vec4;

typedef struct {
    f32 pos[3];
    s32 unk0C;
    f32 off[3];
    s32 unk1C;
} S_468DC0_Sub;

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
    S_468DC0_Sub sub;
} S_468DC0;

extern Vec4 D_001A4C60;
extern u8 *D_002211EC[];
extern S_468DC0 *func_0045E438(s32 size);

S_468DC0 *func_00468DC0(Vec4 *a0, f32 *a1, s32 a2, s32 a3, u8 t0, s32 t1, s32 t2, s32 t3, f32 f12) {
    S_468DC0 *p = func_0045E438(60);
    if (p != 0) {
        S_468DC0_Sub *q = &p->sub;
        p->unk10 = *a0;
        q->pos[0] = a1[0];
        q->pos[1] = a1[1];
        q->pos[2] = a1[2];
        q->unk0C = t3;
        q->unk1C = t1;
        if (t1 == 1) {
            Vec4 v = D_001A4C60;
            q->off[0] = p->unk10.x - v.x;
            q->off[1] = p->unk10.y - v.y;
            q->off[2] = p->unk10.z - v.z;
        }
        p->unk04 = a2;
        p->unk09 = ((t2 >> 5) << 4) + 1;
        p->unk03 = 72;
        p->unk0C = f12 * 210000.0f;
        p->unk08 = t0;
        p->unk01 = 0;
        p->unk02 = *D_002211EC[0];
        p->unk0A = a3;
    }
    return p;
}
