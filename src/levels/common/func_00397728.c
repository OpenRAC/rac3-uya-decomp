#include "common.h"
typedef struct { f32 v[8]; } R00397728;
typedef struct { R00397728 r[4]; } G00397728;
void func_00397728(u8 *a0, s32 a1, s32 a2) {
    s32 i;
    u8 *s = *(u8 **)(a0 + 104);
    for (i = 0; i < 4; i++) {
        if (a2 == 1) {
            ((G00397728 *)(s + 960))[a1].r[i].v[0] = (f32)i * 0.00479965564f + 0.392699093f;
        } else {
            ((G00397728 *)(s + 960))[a1].r[i].v[0] = (f32)i * -0.392699093f;
        }
    }
}
