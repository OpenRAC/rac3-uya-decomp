#include "common.h"

/* localdecomp:start func_005010B8 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_5010B8;
extern u8 D_001A4BE0[];
extern s32 D_001DFBC0;
extern f32 D_001EAAA0[];
extern void func_004EB918(V_5010B8 *, V_5010B8 *, s32, f32, f32);
extern s32 func_003F8448(V_5010B8 *, V_5010B8 *, s32, s32, s32);
extern s32 func_003FC730(void);
extern s32 func_004FC518(s32, s32);
extern void func_004F1068(s32, s32);

s32 func_005010B8(void) {
    u8 *g = D_001A4BE0;
    u8 *h;
    u8 *k;
    u8 *m;
    s32 ret;
    s32 st;
    f32 lim;
    f32 f;
    f32 e;
    s32 fc;
    V_5010B8 a;
    V_5010B8 b;

    if (*(s32 *)(g + 9668) == 121 || *(s32 *)(g + 9668) == 108) {
        return 0;
    }
    ret = 0;
    if (g[5238] != 0) {
        st = *(s32 *)(g + 9676);
        if (st == 17) {
            if (*(s32 *)(g + 9672) != 1 && *(f32 *)(g + 280) > 0.0f &&
                *(f32 *)(g + 848) - 0.4f < *(f32 *)(g + 136)) {
                ret = 1;
            }
            h = D_001A4BE0;
            goto r3;
        } else if (st != 18 && st != 3) {
            lim = 0.2f;
            e = __builtin_fabsf(*(f32 *)(g + 248)) + 0.07f;
            if (e > lim) {
                lim = e;
            }
            if (__builtin_fabsf(*(f32 *)(g + 848) - (*(f32 *)(g + 136) + 0.45f)) < lim &&
                (st != 4 || g[1134] != 0)) {
                if (*(f32 *)(g + 10312) > 0.8f && *(f32 *)(g + 280) < 0.0f) {
                    ret = 1;
                }
            }
            h = D_001A4BE0;
            if (*(f32 *)(h + 848) - 0.8f > *(f32 *)(h + 136) &&
                (*(s32 *)(h + 9676) != 4 || h[1134] != 0)) {
                ret = 1;
            }
        }
    }
    h = D_001A4BE0;
r3:
    st = *(s32 *)(h + 9668);
    if (st == 18 && h[1134] != 0 && *(f32 *)(h + 848) - 0.7f > *(f32 *)(h + 136)) {
        ret = 1;
    }
    k = D_001A4BE0;
    st = *(s32 *)(k + 9676);
    if (!((u32)(st - 17) < 2 || st == 7 || *(s32 *)(k + 9668) == 18)) {
        fc = D_001DFBC0;
        if ((fc & 0xF) == 0) {
            f = 4.0f;
            if (fc % 63 == 0) {
                f = 16.0f;
            }
            func_004EB918(&a, &b, 0, f, 1.3f);
            if (func_003F8448(&a, &b, 2, *(s32 *)(k + 9664), 0) != 0 && func_003FC730() == 0) {
                a.z = D_001EAAA0[2] - 0.01f;
                if (func_003F8448(&a, &b, 2, *(s32 *)(k + 9664), 0) == 0) {
                    if (*(s32 *)(k + 9676) == 20 || *(s32 *)(k + 10320) == 0) {
                        func_004FC518(108, 1);
                    } else {
                        func_004FC518(51, 1);
                    }
                    return 1;
                }
            }
        }
    }
    if (ret != 0) {
        m = D_001A4BE0;
        if (*(s32 *)(m + 9676) == 20 || *(s32 *)(m + 10320) == 0) {
            if (func_004FC518(108, 3) != 0) {
                *(s32 *)(m + 572) = 70;
            }
        } else {
            func_004FC518(54, 1);
        }
        func_004F1068(3, 0);
    }
    return ret;
}
/* localdecomp:end func_005010B8 */
