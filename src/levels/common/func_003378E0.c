#include "common.h"

/* localdecomp:start func_003378E0 */
typedef struct {
    u8 pad0[0x234];
    s32 f234;
    u8 pad238[0x25C4 - 0x238];
    s32 f25C4;
} S_001A4BE0_3378E0;

typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V4_3378E0;

extern S_001A4BE0_3378E0 D_001A4BE0;
extern s32 func_0032FE90(f32 *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
                          s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern f32 func_004408C0(f32, f32);
extern s32 func_00440848(s32);
extern f32 func_00440978(void);
extern void func_00440CF8(void *, f32, f32, f32);
extern f32 func_00440918(f32, f32);
extern void *func_00467DA8(f32 *, s32, s32, s32, s32, f32 *, f32, f32, f32, s32);

void func_003378E0(f32 *pos, s32 n) {
    f32 v[4] __attribute__((aligned(16)));
    V4_3378E0 old;
    f32 scale;
    f32 a;
    f32 b;
    s32 s;
    s32 i;

    if (D_001A4BE0.f234 != 0) {
        s32 l = D_001A4BE0.f25C4;
        if (l == 19 || l == 32 || l == 42 || l == 114 || l == 20) {
            func_0032FE90(pos, 0, 10, 10, 10, 20, 0, 1, 0.5f, 0.0f, 0.0f, 2.0f,
                          0, 1, 0, 0, 0, 0, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF,
                          0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
            return;
        }
    }
    for (i = 0; i < n; i++) {
        scale = func_004408C0(0.1f, 2.0f);
        s = func_00440848(2);
        if (s == 0) {
            s--;
        }
        a = func_00440978();
        b = func_004408C0(0.34906584f, 1.5358897f);
        func_00440CF8(v, func_004408C0(0.05f, 0.1f), a, b);
        old = *(V4_3378E0 *)pos;
        pos[0] += func_00440918(0.0f, 0.15f);
        pos[1] += func_00440918(0.0f, 0.15f);
        pos[2] += func_00440918(0.0f, 0.15f);
        func_00467DA8(pos, 30, 0x7F207F7F, 0, s, v, scale * 0.1f, scale, 0.003f, 0);
        func_00467DA8(pos, 30, 0x7F7F7F7F, 1, -s, v, scale * 0.07f, scale * 0.7f, 0.003f, 0);
    }
}
/* localdecomp:end func_003378E0 */
