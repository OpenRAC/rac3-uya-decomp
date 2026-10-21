#include "common.h"

/* localdecomp:start func_0030EDC0 */
typedef struct {
    u8 pad0[128];
    u8 unk80[8];
    f32 unk88;
    u8 pad8C[9575];
    u8 unk25F3;
    u8 pad25F4[560];
    f32 unk2824;
    f32 unk2828;
    u8 pad282C[36];
    s32 unk2850;
} S_001A4BE0;

typedef struct {
    u8 pad0[138];
    u16 unk8A;
    u8 pad8C[100];
} S_002C5640;

extern S_001A4BE0 D_001A4BE0[];
extern s32 D_001D673C;
extern u8 D_001425C0[];
extern s32 D_001427F0[];
extern S_002C5640 D_002C5640[];

extern f32 func_0044E300(u8 *);
extern s32 func_0040BAF0(u8 *);
extern f32 func_0040C040(u8 *, u8 *);

s32 func_0030EDC0(u8 *obj, s32 arg1) {
    u8 *pv;
    s32 idx;
    f32 d;
    S_001A4BE0 *g;

    g = D_001A4BE0;
    pv = *(u8 **)(obj + 104);
    if (g->unk2850 == 0) {
        return 0;
    }
    if (D_001D673C != 0 ? func_0044E300(obj + 16) < *(f32 *)(pv + 116) - 2.0f : *(f32 *)(obj + 24) < *(f32 *)(pv + 116) - 2.0f) {
        return 1;
    }
    if (g->unk25F3 != 0) {
        return 1;
    }
    idx = *(s32 *)(pv + 104);
    if (D_001427F0[idx] >= (D_001425C0[idx])[D_002C5640].unk8A) {
        return 0;
    }
    if (pv[92] != 0 || arg1 != 0) {
        if (func_0040BAF0(pv + 120) != 0) {
            if (D_001A4BE0[0].unk2828 < __builtin_fabsf(*(f32 *)(obj + 24) - D_001A4BE0[0].unk88)) {
                return 0;
            }
            d = func_0040C040(obj + 16, D_001A4BE0[0].unk80);
            if (D_001A4BE0[0].unk2824 * D_001A4BE0[0].unk2824 < d) {
                return 0;
            }
        }
    } else {
        if (__builtin_fabsf(*(f32 *)(obj + 24) - D_001A4BE0[0].unk88) < D_001A4BE0[0].unk2828) {
            d = func_0040C040(obj + 16, D_001A4BE0[0].unk80);
            if (d < D_001A4BE0[0].unk2824 * D_001A4BE0[0].unk2824) {
                pv[120] = 3;
            }
        }
        return 0;
    }
    return 1;
}
/* localdecomp:end func_0030EDC0 */
