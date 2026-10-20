#include "common.h"

typedef int s128 __attribute__((mode(TI)));

typedef struct {
    u8 p0[0x10];
    f32 pos[4];
} O_3B4CF0;

typedef struct {
    u8 p0[4];
    s32 w4;
    s32 w8;
    u8 pC[0x50];
    s32 w5C;
    s32 w60;
    s32 w64;
    u8 p68[0x48];
    s32 wB0;
    s32 wB4;
    s32 wB8;
    u8 pBC[0xC];
    s32 wC8;
    u8 pCC[4];
    s32 grp[4];
    s32 base[8];
    s32 cnt[4];
} S_3B4CF0;

extern s16 *D_0021DEA0[];
extern s32 D_001E009C;

extern s32 func_00440848(s32);
extern s32 func_003F9498(f32 *, f32, s32, s32);

O_3B4CF0 *func_003B4CF0(S_3B4CF0 *s, f32 f, f32 g, s32 *out) {
    f32 ratio;
    s32 k;
    s32 i;
    s32 j;
    O_3B4CF0 *o;
    f32 v[4] __attribute__((aligned(16)));

    if (s->w60 == 0) {
        ratio = 0.0f;
    } else if (s->w64 == 0) {
        ratio = 1.0f;
    } else {
        ratio = (f32)s->w60 / (f32)(s->w60 + s->w64);
    }
    if ((ratio == 0.0f && 0.0f < f) || ratio <= f) {
        if (out) {
            *out = -1;
        }
        if (s->w5C) {
            k = func_00440848(s->wB4);
        } else {
            k = s->w60 % s->wB4;
        }
        for (i = 0; i < s->wB4; i++) {
            if (k == s->wB0) {
                o = (O_3B4CF0 *)(D_001E009C + (s->w8 << 8));
            } else {
                s16 *t = D_0021DEA0[s->w4];
                t += k;
                o = (O_3B4CF0 *)(D_001E009C + ((*t & 0x7FFF) << 8));
            }
            *(s128 *)v = *(s128 *)o->pos;
            v[2] += g;
            if (g == 0.0f || func_003F9498(v, g, 1, 0) == 0) {
                s->w60++;
                return o;
            }
            k = (k + 1) % s->wB4;
        }
    } else {
        if (out) {
            *out = 0;
        }
        if (s->w5C) {
            k = func_00440848(s->wB8);
        } else {
            k = s->w64 % s->wB8;
        }
        o = 0;
        for (i = 0; i < s->wB4; i++) {
            {
                s32 rem = k;
                for (j = 0; j < s->wC8; j++) {
                    if (rem < s->cnt[j]) {
                        s16 *t = D_0021DEA0[s->grp[j]];
                        t += rem;
                        o = (O_3B4CF0 *)(D_001E009C + ((*t & 0x7FFF) << 8));
                        break;
                    }
                    rem -= s->cnt[j];
                }
                if (j == s->wC8) {
                    o = (O_3B4CF0 *)(D_001E009C + (s->base[rem] << 8));
                    if (out) {
                        *out = rem;
                    }
                } else if (out) {
                    *out = j;
                }
            }
            if (func_003F9498(o->pos, g, 1, 0) == 0) {
                s->w64++;
                return o;
            }
            k = (k + 1) % s->wB8;
        }
    }
    return 0;
}
