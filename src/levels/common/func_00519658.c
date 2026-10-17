#include "common.h"

extern f32 D_001DC128;
extern f32 D_001DC12C;
extern void func_004C20A8(s32, s32, s32, s32);
void func_00519658(f32 a, f32 b, f32 c, f32 d) {
    func_004C20A8((s32)(a * D_001DC128), (s32)(c * D_001DC128), (s32)(b * D_001DC12C), (s32)(d * D_001DC12C));
}
