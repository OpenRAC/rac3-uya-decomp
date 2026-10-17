#include "common.h"

typedef int u128_48F320 __attribute__((mode(TI)));
typedef union {
    u128_48F320 q;
    f32 f[4];
} V_48F320;
typedef struct {
    V_48F320 pos;
    u8 pad10[0x10];
    s16 link[8];
    u8 pad30[0x30];
} N_48F320;
extern s32 D_002487A8;
extern N_48F320 D_00292860[];
extern void func_0048FAE8(V_48F320 *, s32, f32);
extern void func_0048F818(V_48F320 *, V_48F320 *, s32, f32);

void func_0048F320(void) {
    s32 i, j;
    V_48F320 a, b;

    for (i = 0; i < D_002487A8; i++) {
        a = D_00292860[i].pos;
        a.f[2] += 0.05f;
        func_0048FAE8(&a, 0x6000FF00, 0.4f);
        for (j = 0; j < 8; j++) {
            if (D_00292860[i].link[j] >= i) {
                b = D_00292860[D_00292860[i].link[j]].pos;
                b.f[2] += 0.05f;
                func_0048F818(&a, &b, 0x60008000, 0.2f);
            }
        }
    }
}
