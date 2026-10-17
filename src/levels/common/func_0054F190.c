#include "common.h"

typedef struct {
    f32 v[4];
} __attribute__((aligned(16))) Vec4;

extern s32 D_001D5A08;
extern void func_005A98E8(void *, s32, Vec4 *);
extern void func_0054F558(Vec4 *, s32, f32, f32, f32, f32);

void func_0054F190(u8 *arg0) {
    Vec4 v;
    u8 *p;

    if (arg0 != 0 && *(s16 *)(arg0 + 170) == 4246 && arg0[32] != 254 && arg0[32] != 253) {
        p = *(u8 **)(arg0 + 104);
        if (p != 0 && (*(u8 **)(p + 60))[9417] == D_001D5A08) {
            func_005A98E8(arg0, 0, &v);
            func_0054F558(&v, 120, 1.0f, 0.0f, 0.0f, 0.9f);
        }
    }
}
