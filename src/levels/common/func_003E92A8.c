#include "common.h"
typedef struct {
    u8 pad0[292];
    s32 w124;
    u8 pad128[672 - 296];
    s16 h2A0;
    u8 b2A2;
    u8 b2A3;
    u8 pad2A4[696 - 676];
    f32 f2B8;
    u8 pad2BC[712 - 700];
    f32 f2C8;
    u8 pad2CC[1120 - 716];
} Entry_3E92A8;
extern Entry_3E92A8 D_001E2AC0[];
extern void func_003E8C50(u8 *);
extern void func_004A7200(s32, s32, s32);
void func_003E92A8(u8 *a0) {
    Entry_3E92A8 *e = &D_001E2AC0[*(s32 *)(a0 + 148)];
    if (e->h2A0 != 0) {
        e->h2A0 = 2;
    } else {
        e->h2A0 = 1;
    }
    e->b2A3 = 0;
    (D_001E2AC0 + *(s32 *)(a0 + 148))->f2C8 = 0.075f;
    D_001E2AC0[*(s32 *)(a0 + 148)].f2B8 = 0.075f;
    func_003E8C50(a0);
    if (e->w124) {
        func_004A7200(0, 0, e->w124);
    }
}
