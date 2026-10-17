#include "common.h"
extern void func_005B5118(f32 *, f32, f32);
void func_00630DD8(u8 *a, f32 x, f32 y) {
    f32 t = *(f32 *)(a + 4016);
    if (*(f32 *)(a + 4020) < t) {
        func_005B5118((f32 *)(a + 4020), t, x);
    } else {
        func_005B5118((f32 *)(a + 4020), t, y);
    }
}
