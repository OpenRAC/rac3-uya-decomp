#include "common.h"

extern void func_0039E3B8(s32 id, s32 on);
extern void func_00419630(void *m, s32 a, s32 b, s32 c);
extern void func_00419970(void *m, s32 a, s32 b);
extern u8 *D_001DEA1C;

void func_0039E460(u8 *m) {
    u8 *t = D_001DEA1C;
    s32 *v = *(s32 **)(m + 0x68);
    v[2] = 0;
    v[3] = 0;
    v[4] = 0;
    *(f32 *)(m + 0x2C) = *(f32 *)(*(u8 **)(m + 0x24) + 0x24) * 2.5f;
    *(s16 *)(t + (v[0] << 8) + 0x36) = 0x7F80;
    func_0039E3B8(v[0], 1);
    if (v[1] != -1) {
        *(s16 *)(D_001DEA1C + (v[1] << 8) + 0x36) = 0x7F80;
        func_0039E3B8(v[1], 1);
    }
    if (m[0x43] != 0) {
        func_00419630(m, 0, 0, 0);
    }
    func_00419970(m, 1, 1);
}
