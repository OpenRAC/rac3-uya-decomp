#include "common.h"
extern f32 func_0040C490(f32, f32);
extern void func_00457590(f32 *, f32 *, f32);
void func_00457440(f32 *a0, f32 *a1) {
    func_00457590(a0, a1, func_0040C490(a1[0] - a0[4], a1[1] - a0[5]));
}
