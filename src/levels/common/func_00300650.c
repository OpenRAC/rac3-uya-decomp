#include "common.h"

typedef int u128_t __attribute__((mode(TI)));
extern u8 *func_00435E70(s32, s32);
extern void func_004475D0(u8 *);
extern void func_00439610(u8 *);
/* localdecomp:start func_00300650 */
u8 *func_00300650(u8 *src, u128_t *pos, s32 arg, u128_t *alt) {
    u8 *m;
    u8 *pv;
    m = func_00435E70(639, 128);
    if (m != 0) {
        m[48] = 255;
        m[49] = 1;
        *(u16 *)(m + 52) |= 1;
        m[32] = 0;
        m[188] = 0;
        pv = *(u8 **)(m + 104);
        *(u128_t *)(m + 16) = *pos;
        if (alt != 0)
            *(u128_t *)pv = *alt;
        else
            *(u128_t *)pv = *(u128_t *)src;
        *(s32 *)(pv + 32) = arg;
        *(s16 *)(m + 50) = src[60];
        pv[36] = src[16];
        pv[37] = src[17];
        pv[38] = src[18];
        pv[39] = src[19];
        pv[40] = src[20];
        pv[41] = src[21];
        pv[104] = src[61];
        *(u16 *)(pv + 108) = *(u16 *)(src + 64);
        pv[42] = src[22];
        pv[43] = src[23];
        pv[44] = src[24];
        pv[45] = src[25];
        pv[46] = src[26];
        pv[105] = src[62];
        *(u16 *)(pv + 110) = *(u16 *)(src + 66);
        pv[47] = src[27];
        pv[48] = src[28];
        pv[49] = src[29];
        pv[50] = src[30];
        pv[51] = src[31];
        pv[106] = src[63];
        *(u16 *)(pv + 112) = *(u16 *)(src + 68);
        *(f32 *)(pv + 52) = *(f32 *)(src + 32);
        *(f32 *)(pv + 56) = *(f32 *)(src + 36);
        *(f32 *)(pv + 60) = *(f32 *)(src + 40);
        *(f32 *)(pv + 64) = *(f32 *)(src + 44);
        *(f32 *)(pv + 68) = *(f32 *)(src + 48);
        pv[107] = src[72];
        *(u16 *)(pv + 114) = *(u16 *)(src + 70);
        *(s32 *)(pv + 72) = *(s32 *)(src + 52);
        *(s32 *)(pv + 76) = *(s32 *)(src + 56);
        pv[28] = src[73];
        *(s32 *)(pv + 100) = -1;
        func_00439610(m);
        func_004475D0(m);
    }
    return m;
}
/* localdecomp:end func_00300650 */
