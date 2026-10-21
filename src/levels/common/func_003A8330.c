#include "common.h"

typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V4_3A8330;

extern s32 D_001DE2F0;
extern void func_003EECD0(void *p);

void func_003A8330(u8 *moby) {
    u8 *pv = *(u8 **)(moby + 0x68);
    if (pv != 0) {
        V4_3A8330 c = {128.0f, 128.0f, 128.0f};
        f32 t;
        c.w = 255.0f;
        func_003EECD0(pv + 0x10);
        t = (f32)*(s32 *)(pv + 0x10) / (f32)D_001DE2F0;
        *(u32 *)(moby + 0x78) = ((s32)((c.z - 64.0f) * t + 64.0f) << 16) | 0xFF000000
            | ((s32)((c.y - 64.0f) * t + 64.0f) << 8)
            | (s32)((c.x - 255.0f) * t + 255.0f);
    }
}
