#include "common.h"

extern u8 D_001D7EDC;
extern s32 D_001D7ED8;
extern s32 *D_002412A0[];
extern f32 D_0024C3A8[];
extern f32 D_0024C3AC[];
extern f32 D_0024C3B0[];
extern f32 D_0024C3B4[];
extern void func_0060F828(s32);
extern void func_0060E900(s32, s32, s32);

void func_005D67A8(s32 a0, f32 *a1, f32 *a2) {
    if (D_001D7EDC) {
        func_0060F828(*D_002412A0[0] < 2 ? 0 : 4);
        D_001D7ED8 = a0;
        D_0024C3A8[0] = a1[0];
        D_0024C3AC[0] = a1[1];
        D_0024C3B0[0] = a2[0];
        D_0024C3B4[0] = a2[1];
        func_0060E900(0x70000, 1, 1);
    }
}
