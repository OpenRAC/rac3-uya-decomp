#include "common.h"

/* localdecomp:start func_003F13A8 */
f32 func_003F13A8(f32 *arg0, f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3, f32 fparg4) {
    f32 temp_f0;
    f32 temp_f13;
    f32 temp_f1;
    f32 temp_f1_2;
    f32 var_f13;
    f32 var_f16;

    var_f16 = fparg4;
    temp_f13 = fparg1 - fparg0;
    temp_f1 = *arg0;
    temp_f1_2 = temp_f1 + ((fparg2 * temp_f13) - (fparg3 * temp_f1));
    *arg0 = temp_f1_2;
    if ((var_f16 != 0.0f) && ((var_f16 < temp_f1_2) || (var_f16 = -var_f16, (temp_f1_2 < var_f16)))) {
        *arg0 = var_f16;
    }
    temp_f0 = *arg0;
    __asm__("abs.s %0, %1" : "=f"(var_f13) : "f"(temp_f13));
    if ((var_f13 < temp_f0) || (var_f13 = -var_f13, (temp_f0 < var_f13))) {
        *arg0 = var_f13;
    }
    return fparg0 + *arg0;
}
/* localdecomp:end func_003F13A8 */
