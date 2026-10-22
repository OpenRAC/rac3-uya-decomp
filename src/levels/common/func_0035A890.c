#include "common.h"

typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_0035A890;

extern void func_0035A630(void *a0, void *a1, V4_0035A890 *out);
extern s32 func_00376310(void *a0);
extern f32 func_0041C888(void *a0, V4_0035A890 *b);
extern u8 D_001439F4[];
extern s32 D_001A71A4[];

s32 func_0035A890(void *a0, u8 *a1, s32 a2) {
    V4_0035A890 v;
    f32 d;

    if (!((D_001A71A4[0] == 1 || D_001439F4[0] != 0) && func_00376310(a0) != 0) && a2 == 0) {
        return 0;
    }
    if (*(s32 *)(a1 + 4) != 0) {
        func_0035A630(a0, a1, &v);
        d = func_0041C888((u8 *)*(s32 *)(a1 + 4) + 0x10, &v);
    } else {
        d = 2.4f;
    }
    return d > 1.2f;
}
