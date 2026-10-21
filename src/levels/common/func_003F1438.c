#include "common.h"

extern void func_003F1438(f32 *, f32, f32, f32, f32, f32);

extern void func_0040CEC8(f32, f32);
extern f32 func_0040CF10(f32, f32);
void func_003F1438(f32 *arg0, f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3, f32 fparg4) {
    f32 temp_f0;
    f32 temp_f1;
    f32 temp_f1_2;
    f32 temp_f1_3;
    f32 var_f0;
    f32 var_f16;

    var_f16 = fparg4;
    temp_f0 = func_0040CF10(fparg1, fparg0);
    temp_f1 = *arg0;
    temp_f1_2 = temp_f1 + ((fparg2 * temp_f0) - (fparg3 * temp_f1));
    *arg0 = temp_f1_2;
    if (var_f16 != 0.0f) {
        if (var_f16 < temp_f1_2) {
            *arg0 = var_f16;
        } else {
            f32 n = -var_f16;
            if (temp_f1_2 < n) {
                *arg0 = n;
            }
        }
    }
    temp_f1_3 = *arg0;
    __asm__("abs.s %0, %1" : "=f"(var_f0) : "f"(temp_f0));
    if ((var_f0 < temp_f1_3) || (var_f0 = -var_f0, (temp_f1_3 < var_f0))) {
        *arg0 = var_f0;
    }
    func_0040CEC8(fparg0, *arg0);
}
