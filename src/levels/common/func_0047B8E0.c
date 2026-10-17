#include "common.h"

extern void func_0047B8E0(s32);

extern f32 D_001D82E8;
extern s32 func_0040D020(f32, s32, s32);
extern s32 func_005130C8(s32, s32);
void func_0047B8E0(s32 a) {
    func_005130C8(a, ((s32 (*)(s32, s32, f32))func_0040D020)(0x20000000, 0x402299DE, D_001D82E8));
}
