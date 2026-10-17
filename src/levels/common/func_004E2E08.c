#include "common.h"

typedef struct {
    u8 pad0[0x43];
    u8 type;
} Moby;

typedef struct {
    u8 pad0[0xC08];
    s32 flags;
    u8 padC0C[0xEB4];
    s32 field_1AC0;
    u8 pad1AC4[0xAFC];
    Moby *moby;
    s32 state;
    u8 pad25C8[4];
    s32 field_25CC;
    u8 pad25D0[0x19];
    u8 field_25E9;
    u8 pad25EA;
    u8 field_25EB;
} Game;

extern Game D_001A4BE0;
extern void func_004DC648(s32, s32, f32);

void func_004E2E08(void) {
    s32 t;

    if ((D_001A4BE0.flags & 2) && D_001A4BE0.field_25EB == 0) {
        t = D_001A4BE0.moby->type;
        if (t == 19 || t == 22 || t == 25 || t == 28 || t == 31) {
            func_004DC648(D_001A4BE0.moby->type - 2, 0, 4.0f);
        }
        D_001A4BE0.field_25E9 = 0;
    }
    if (D_001A4BE0.field_25CC != 0 && D_001A4BE0.field_1AC0 == 0) {
        D_001A4BE0.field_25E9 = 0;
    }
}
