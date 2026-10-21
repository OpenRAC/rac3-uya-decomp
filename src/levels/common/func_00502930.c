#include "common.h"

typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) Vec4;

typedef struct {
    u8 pad0[80];
    s32 w80;
    s32 pad84;
    f32 f88;
    s32 pad92;
    s32 w96;
    u8 pad100[12];
} T_502930;

extern u8 D_001A4BE0[];
extern T_502930 D_002F4370[];
extern s32 D_002F4520[];
extern s32 D_001D545C;
extern s32 func_004DC080(void);
extern f32 func_004408C0(f32, f32);
extern s32 func_004E5470(s32);
extern s32 func_003F8448(Vec4 *, Vec4 *, s32, s32, s32);

/* localdecomp:start func_00502930 */
s32 func_00502930(s32 *out) {
    s32 list[20];
    Vec4 b;
    Vec4 a;
    s32 n;
    s32 i;
    T_502930 *p;
    T_502930 *e;
    u8 *g;
    f32 sum;
    f32 r;

    g = D_001A4BE0;
    n = 0;
    if (*(s16 *)(g + 520) != 0) {
        return 0;
    }
    if (func_004DC080()) {
        *out = 3;
        if (D_002F4520[0] != 0) {
            return 0;
        }
        if (!(*(s32 *)(g + 3080) & 2)) {
            return 0;
        }
        if (func_004408C0(0.0f, 1.0f) < 0.33f) {
            return 1;
        }
        return 0;
    }
    for (i = 0; i < 4; i++) {
        p = &D_002F4370[i];
        if (p->w96 != 0) {
            continue;
        }
        if (p->f88 == 0.0f) {
            continue;
        }
        {
            s32 v = func_004E5470(0);
            if (p->w80 != -1 && p->w80 != v) {
                continue;
            }
        }
        if (i == 2) {
            u8 *h;
            if (D_001D545C != -1) {
                continue;
            }
            h = D_001A4BE0;
            if (h[9708] == 2) {
                continue;
            }
            a = b = *(Vec4 *)(h + 224);
            b.z += 8.0f;
            if (func_003F8448(&a, &b, 2, *(s32 *)(h + 9664), 0)) {
                continue;
            }
        }
        if (i == 3) {
            u8 *h;
            h = D_001A4BE0;
            if (*(s32 *)(h + 9684) != 1 || *(s32 *)(h + 440) >= 51 || *(s32 *)(h + 10320) >= 2) {
                continue;
            }
        }
        list[n++] = i;
    }
    if (n == 0) {
        return 0;
    }
    sum = 0.0f;
    for (i = 0; i < n; i++) {
        sum += 1.0f / (f32)(s32)((&D_002F4370[list[i]])->f88 * 60.0f);
    }
    r = func_004408C0(0.0f, 1.0f);
    if (r < sum) {
        for (i = 0; i < n; i++) {
            *out = list[i];
            e = &D_002F4370[list[i]];
            sum -= 1.0f / (f32)(s32)(e->f88 * 60.0f);
            if (sum < r) {
                break;
            }
        }
        return 1;
    }
    return 0;
}
/* localdecomp:end func_00502930 */
