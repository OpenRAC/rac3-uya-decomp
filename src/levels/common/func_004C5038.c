#include "common.h"

typedef struct {
    u8 pad0[4608];
    s32 f4608;
    u8 pad4612[36];
    s32 f4648;
} Game_004C5038;

typedef struct {
    u8 pad0[28];
    s32 f28;
} Ent_004C5038;

extern Game_004C5038 D_001A4BE0;
extern s32 D_001D6694;
extern s32 D_001DD2D8;
extern Ent_004C5038 D_0028CB20[];
extern void func_00322E00(s32);
extern f32 func_004C5828(void);
extern void func_00343020(s32);
extern void func_003F0FA0(s32, s32, s32, f32, f32, f32, f32);
extern void func_004AD960(s32);

void func_004C5038(void) {
    s32 i;

    if (D_001A4BE0.f4648 == 71 && D_001D6694 == 6) {
        func_00322E00(D_001A4BE0.f4608);
    }
    if (func_004C5828() != 0.0f && D_001D6694 != 0 && D_001DD2D8 != 0) {
        func_00343020(D_001DD2D8);
    }
    if (D_001A4BE0.f4648 == 135 && D_001D6694 != 0) {
        for (i = 199; i >= 0; i--) {
            D_0028CB20[i].f28 = 0;
        }
    }
    if (D_001A4BE0.f4648 == 111 && D_001D6694 == 8) {
        func_003F0FA0(0, 0, 3, 1.1100293f, 0.005f, 0.2f, 0.0f);
        func_004AD960(1);
    }
}
