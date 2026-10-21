#include "common.h"

/* localdecomp:start func_004EEC00 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_4EEC00;
typedef struct {
    u8 pad0[64];
    V4_4EEC00 m[4];
    V4_4EEC00 pos;
    u8 pad90[860 - 144];
    s32 f35C;
    u8 pad360[872 - 864];
    s16 f368;
    u8 pad36A[9668 - 874];
    s32 f25C4;
    u8 pad25C8[9707 - 9672];
    u8 f25EB;
    u8 f25EC;
    u8 pad25ED[9716 - 9709];
    u8 f25F4;
    u8 pad25F5[10356 - 9717];
    s16 f2874;
} S_4EEC00;
extern s32 D_001D545C;
extern S_4EEC00 D_001A4BE0;
extern f32 D_002F4580[];
extern void func_0040C2F8(void *, void *, void *);
extern void func_004E25E0(f32, f32);
extern f32 func_0040BFB0(void *, void *);
void func_004EEC00(void) {
    V4_4EEC00 v;
    f32 lim, a, b, c;
    s32 t, near;

    if (D_001D545C == 21) {
        return;
    }
    if (D_001A4BE0.f368 != 0 && D_001A4BE0.f25EB == 0) {
        v = (V4_4EEC00){ 0.0f, 0.0f, -1.0f };
        func_0040C2F8(&v, &v, D_001A4BE0.m);
        func_004E25E0(0.0130000003f, 0.300000012f);
        t = D_001A4BE0.f25C4;
        lim = 0.366519153f;
        if (t == 114) {
            lim = 0.0872664601f;
        } else if (t == 115 || t == 4) {
            lim = 0.191986218f;
        }
        if (D_001A4BE0.f25EC != 0 && 0.122173049f < lim) {
            lim = 0.122173049f;
        }
        if (D_001A4BE0.f35C != 0 && 0.157079637f < lim) {
            lim = 0.157079637f;
        }
        if (D_001A4BE0.f2874 == 0) {
            a = v.x * 0.69813168f;
            if (lim < a) {
                a = lim;
            } else if (a < -lim) {
                a = -lim;
            }
            D_002F4580[276 / 4] = a;
            D_002F4580[628 / 4] = -a * 0.5f;
            if (D_001A4BE0.f25EC != 0) {
                D_002F4580[1508 / 4] = -a;
                D_002F4580[1684 / 4] = -a;
            }
        }
        c = -v.y * 0.69813168f;
        if (lim < c) {
            c = lim;
        } else if (c < -lim) {
            c = -lim;
        }
        D_002F4580[272 / 4] = c;
        D_002F4580[624 / 4] = -c * 0.25f;
        b = -v.x * 1.22173047f;
        if (0.994837642f < b) {
            b = 0.994837642f;
        }
        if (b < -0.122173049f) {
            b = -0.122173049f;
        }
        if (0.850000024f < v.z) {
            if (b < 1.39626336f) {
                b = 1.39626336f;
            }
        } else if (0.5f < v.z) {
            if (b < 1.22173047f) {
                b = 1.22173047f;
            }
        }
        c = v.y * 1.22173047f;
        D_002F4580[2388 / 4] = b * 0.569999993f;
        D_002F4580[2564 / 4] = b * 0.5f;
        D_002F4580[2916 / 4] = b * 0.349999994f;
        D_002F4580[2740 / 4] = b * 0.5f;
        if (1.22173047f < c) {
            c = 1.22173047f;
        } else if (c < -1.22173047f) {
            c = -1.22173047f;
        }
        D_002F4580[2912 / 4] = c;
        D_002F4580[2384 / 4] = c * 0.699999988f;
        D_002F4580[2560 / 4] = c * 0.699999988f;
        D_002F4580[2736 / 4] = c * 0.699999988f;
    }
    if (D_001A4BE0.f25F4 == 1) {
        v = (V4_4EEC00){ 330.0f, 245.0f, 138.0f };
        near = 0;
        if (func_0040BFB0(&D_001A4BE0.pos, &v) < 35.0f) {
            near = 1;
        }
        if (D_001A4BE0.f25EC != 0 && near) {
            D_002F4580[1748 / 4] = 0.0500000007f;
            D_002F4580[1752 / 4] = 0.300000012f;
            D_002F4580[1684 / 4] = -0.226892799f;
            D_002F4580[1508 / 4] = -0.226892799f;
            D_002F4580[1576 / 4] = 0.300000012f;
            D_002F4580[1572 / 4] = 0.0500000007f;
        }
    }
}
/* localdecomp:end func_004EEC00 */
