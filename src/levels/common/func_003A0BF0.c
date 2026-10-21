#include "common.h"

typedef int u128_3A0BF0 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3A0BF0;

typedef struct {
    s32 n;
    u8 pad4[0xC];
    V4_3A0BF0 v[1];
} B_3A0BF0;

typedef struct {
    s32 a;
    s32 b;
} P_3A0BF0;

typedef struct {
    u8 pad0[0x14];
    s32 i14;
    u8 pad18[0x30 - 0x18];
    f32 f30;
    u8 pad34[0x3C - 0x34];
    s32 i3C;
    f32 f40;
    u8 pad44[4];
    f32 f48;
    f32 f4C;
    f32 f50;
    f32 f54;
    f32 f58;
    u8 pad5C[4];
    P_3A0BF0 p60[4];
    V4_3A0BF0 v80;
    u8 pad90[8];
    s32 i98;
} S_3A0BF0;

extern void func_003E4590(V4_3A0BF0 *out, V4_3A0BF0 *a, V4_3A0BF0 *b, f32 t);
extern void func_00419970(void *m, s32 a, s32 b);
extern u8 *D_001DEA1C;
extern B_3A0BF0 *D_0021C780[];

void func_003A0BF0(u8 *m, S_3A0BF0 *s) {
    V4_3A0BF0 lo;
    V4_3A0BF0 hi;
    B_3A0BF0 *b;
    s32 i;
    s32 j;

    m[0x30] = 0xFF;
    s->i14 *= 2;
    if (s->i14 >= 5) {
        s->i14 = 4;
    } else if (s->i14 < 0) {
        s->i14 = 0;
    }
    for (j = 0; j < 4; j++) {
        s->p60[j].a = 0;
        s->p60[j].b = 0;
    }
    s->f30 = 0.0f;
    if (s->f40 != s->f30) {
        if (s->f40 < s->f30) {
            s->f50 = -1.0f;
            s->f40 = -s->f40;
        } else {
            s->f50 = 1.0f;
        }
        s->f40 = 360.0f / s->f40 * 60.0f;
        s->f48 = 1.0f / s->f48;
        s->f4C = 1.0f / s->f4C;
    }
    if (s->f54 != 0.0f) {
        s->f54 = s->f54 * 0.016666668f;
    }
    if (s->f58 != 0.0f) {
        s->f58 = s->f58 * 0.016666668f;
    }
    b = D_0021C780[s->i3C];
    *(u128_3A0BF0 *)&lo = *(u128_3A0BF0 *)&b->v[0];
    *(u128_3A0BF0 *)&hi = *(u128_3A0BF0 *)&b->v[0];
    for (i = 1; i < b->n; i++) {
        if (lo.x > b->v[i].x) {
            lo.x = b->v[i].x;
        }
        if (lo.y > b->v[i].y) {
            lo.y = b->v[i].y;
        }
        if (lo.z > b->v[i].z) {
            lo.z = b->v[i].z;
        }
        if (hi.x < b->v[i].x) {
            hi.x = b->v[i].x;
        }
        if (hi.y < b->v[i].y) {
            hi.y = b->v[i].y;
        }
        if (hi.z < b->v[i].z) {
            hi.z = b->v[i].z;
        }
    }
    func_003E4590(&s->v80, &lo, &hi, 0.5f);
    if (s->i98 != -1) {
        *(u16 *)(D_001DEA1C + (s->i98 << 8) + 0x34) |= 0x41;
    }
    func_00419970(m, 1, -1);
}
