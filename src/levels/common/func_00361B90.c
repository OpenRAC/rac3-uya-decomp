#include "common.h"

/* localdecomp:start func_00361B90 */
extern void *func_00455480(void);
extern void func_00451098(void *, s32, s32, s32);

void func_00361B90(u8 *self, u8 *src) {
    u8 *v;
    u8 *sv;
    u8 *ov;
    f32 f;

    v = *(u8 **)(self + 0x68);
    ov = *(u8 **)(*(u8 **)((u8 *)func_00455480() + 8) + 0x68);
    sv = *(u8 **)(src + 0x68);
    v[0x25D] = sv[0x80];
    *(s32 *)(v + 0x2E0) = *(s32 *)(sv + 0x0);
    f = *(f32 *)(sv + 0x4);
    if (f > 0.0f) {
        *(f32 *)(v + 0x2E4) = f;
    }
    *(s32 *)(v + 0x2E8) = *(s32 *)(sv + 0x8);
    f = *(f32 *)(sv + 0xC);
    if (f > 0.0f) {
        *(f32 *)(v + 0x2EC) = f;
    }
    *(s32 *)(v + 0x300) = *(s32 *)(sv + 0x14);
    *(s32 *)(v + 0x304) = *(s32 *)(sv + 0x20);
    *(s32 *)(v + 0x38C) = *(s32 *)(sv + 0x68);
    *(s32 *)(v + 0x308) = *(s32 *)(sv + 0x24);
    *(s32 *)(v + 0x30C) = *(s32 *)(sv + 0x10);
    *(s32 *)(v + 0x310) = *(s32 *)(sv + 0x28);
    *(s32 *)(v + 0x314) = *(s32 *)(sv + 0x2C);
    *(s32 *)(v + 0x318) = *(s32 *)(sv + 0x1C);
    *(s32 *)(v + 0x31C) = *(s32 *)(sv + 0x18);
    *(s32 *)(v + 0x4D0) = *(s32 *)(sv + 0x74);
    *(s32 *)(v + 0x4D4) = *(s32 *)(sv + 0x78);
    *(s32 *)(v + 0x500) = *(s32 *)(sv + 0x88);
    *(s32 *)(v + 0x374) = *(s32 *)(ov + 0x78);
    if (self[0x43] != 0) {
        func_00451098(self, 0, 0, 0);
    }
}
/* localdecomp:end func_00361B90 */
