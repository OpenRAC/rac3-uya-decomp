#include "common.h"

extern s32 D_001DDAE4;

void func_00357150(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 104);
    s32 t = D_001DDAE4;
    s32 cur = *(s32 *)(p + 220);
    f32 fc = cur;
    s32 end = *(s32 *)(p + 216);

    if (cur < t) {
        *(f32 *)(p + 208) = fc / t;
        return;
    }
    if (end - t < cur) {
        *(f32 *)(p + 208) = (f32)(cur - end) / (f32)(-t);
        return;
    }
    *(f32 *)(p + 208) = 1.0f;
}
