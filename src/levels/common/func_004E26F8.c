#include "common.h"

typedef struct {
    u8 pad0[546];
    s16 unk222;
    u8 pad224[4988];
    f32 unk15A0;
    u8 pad15A4[268];
    s32 unk16B0;
    u8 pad16B4[3893];
    u8 unk25E9;
    u8 pad25EA[2];
    u8 unk25EC;
    u8 pad25ED[3];
    u8 unk25F0;
    u8 pad25F1[643];
    s16 unk2874;
} S_001A4BE0;

typedef struct {
    u8 pad0[516];
    f32 unk204;
} S_001A4C60;

typedef struct {
    f32 f[440];
} S_002F4580;

extern S_001A4BE0 D_001A4BE0;
extern S_001A4C60 D_001A4C60;
extern S_002F4580 D_002F4580;
extern s32 D_001EAA98[];
extern u8 D_001EAAA0[];

extern s32 func_004E2628(s32, f32, f32);
extern s32 func_00447CA0(s32);
extern f32 func_0040BFB0(void *, u8 *);
extern f32 func_0040CF10(f32, f32);
extern s32 func_004E5470(s32);

/* localdecomp:start func_004E26F8 */
void func_004E26F8(void) {
    f32 a;
    f32 lim;
    f32 b;
    f32 t;
    f32 lo;
    f32 hi;
    s32 v;

    D_001A4BE0.unk2874 = 0;
    if (D_001A4BE0.unk25EC == 0) {
        return;
    }
    if (D_001A4BE0.unk222 != 0) {
        return;
    }
    if (D_001A4BE0.unk25F0 != 0) {
        return;
    }
    t = 0.57f;
    if (D_001A4BE0.unk25E9 != 0) {
        t = 0.7f;
    }
    a = 0.0f;
    if (func_004E2628(0, t, 1.3f) != 0) {
        if (D_001A4BE0.unk25E9 == 0 || D_001EAA98[0] == 0 || func_00447CA0(D_001EAA98[0]) == 0) {
            a = ((1.3f - (func_0040BFB0(&D_001A4C60, D_001EAAA0) - D_001A4C60.unk204)) / 1.3f) * 1.25f * -1.2217304706573486f;
            if (-0.5235987901687622f < a) {
                a = -0.5235987901687622f;
            }
            if (a < -1.2217304706573486f) {
                a = -1.2217304706573486f;
            }
        }
        D_001A4BE0.unk2874 = 1;
    }
    if (D_001A4BE0.unk16B0 == 1) {
        lo = -1.3962633609771729f;
        hi = 0.7853981852531433f;
        if (D_001A4BE0.unk2874 == 0 || D_001A4BE0.unk15A0 < a) {
            a = D_001A4BE0.unk15A0;
            if (hi < a) {
                a = hi;
            } else if (a < lo) {
                a = lo;
            }
            D_001A4BE0.unk2874 = 0;
        }
    }
    if (a == 0.0f) {
        return;
    }
    lim = -0.6108652353286743f;
    if (a < lim) {
        D_002F4580.f[85] = 0.05f;
        D_002F4580.f[86] = 0.3f;
        D_002F4580.f[69] = func_0040CF10(a, lim);
        a = lim;
    }
    D_002F4580.f[437] = 0.05f;
    D_002F4580.f[438] = 0.3f;
    b = 0.0f;
    v = func_004E5470(0);
    if (v == 63 || v == 151) {
        b = a * 0.009973309934139252f;
        if (0.6981316804885864f < b) {
            b = 0.6981316804885864f;
        }
    }
    D_002F4580.f[421] = a;
    D_002F4580.f[420] = b;
    if (D_001A4BE0.unk25EC == 2) {
        D_002F4580.f[393] = D_002F4580.f[437];
        D_002F4580.f[394] = D_002F4580.f[438];
        D_002F4580.f[377] = a;
        D_002F4580.f[376] = b;
    }
}
/* localdecomp:end func_004E26F8 */
