#include "common.h"

extern f32 D_001A4C60[];
extern void func_003459B0(f32, f32, f32, f32, f32, f32, f32);

void func_00345960(f32 a, f32 b, f32 c, f32 d, f32 e, f32 f) {
    func_003459B0(D_001A4C60[0], a, b, c, d, e, f);
}
