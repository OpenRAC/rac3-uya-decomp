#include "common.h"

extern u8 *D_001D52FC[];
extern s32 D_001D8874;
extern s32 D_001D87C0;
extern s32 func_004A7368(s32, s32, s32);
extern void func_00485C80(void);
extern s32 func_00484650(void);
extern s32 func_0048A060(void);
extern void func_00513758(s32);
extern s32 func_00486758(void);
extern void func_005120B8(s32);
extern void func_005129D8(s32, f32);

void func_00485D70(void) {
    u32 pad = *(u32 *)(D_001D52FC[0] + 452);
    s32 v;

    if (pad & 4) {
        func_004A7368(3, 0, 0);
        D_001D8874--;
    } else if (pad & 8) {
        func_004A7368(3, 0, 0);
        D_001D8874++;
    } else if (pad & 0x40) {
        func_004A7368(4, 0, 0);
        func_00485C80();
    } else if (pad & 0x80) {
        func_004A7368(4, 0, 0);
        if (D_001D87C0 == 0) {
            D_001D87C0 = 1;
        } else {
            D_001D87C0 = 0;
        }
    } else if (pad & 1) {
        func_004A7368(4, 0, 0);
        func_00513758(func_00484650());
        func_005120B8(func_00486758());
    } else if (pad & 2) {
        func_004A7368(4, 0, 0);
        func_00513758(func_0048A060());
        func_005120B8(func_00486758());
    }
    v = D_001D8874;
    {
        s32 m = 7;
        if (v < 0) {
            v = m;
        }
        if (m < v) {
            v = 0;
        }
    }
    D_001D8874 = v;
    func_005129D8(0x190001, v);
}
