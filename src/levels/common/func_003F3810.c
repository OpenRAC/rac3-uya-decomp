#include "common.h"

extern u8 D_001A4BE0[];
extern s32 func_0044FB80(void *, s32, s32);
extern f32 func_0041C8F0(void *, void *);

u8 func_003F3810(u8 *m) {
    u8 *g = D_001A4BE0;
    u8 *v = *(u8 **)(m + 0x68);
    s32 id;

    if (*(s32 *)(g + 0x360) == 0) {
        return 0;
    }
    id = *(s32 *)(v + 0x14);
    if (id != -1) {
        return func_0044FB80(g + 0x80, id, 0);
    }
    return func_0041C8F0(m + 0x10, g + 0x80) < *(f32 *)(v + 0x18) * *(f32 *)(v + 0x18);
}
