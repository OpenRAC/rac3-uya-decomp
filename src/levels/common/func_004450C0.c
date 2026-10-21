#include "common.h"

/* localdecomp:start func_004450C0 */
extern f32 func_004450C0(f32 *, f32, f32);

f32 func_004450C0(f32 *arg0, f32 fparg0, f32 fparg1) {
    f32 temp_f1;
    f32 var_f0;
    f32 var_f13;

    var_f13 = fparg1;
    var_f0 = fparg0 - *arg0;
    if ((var_f13 < var_f0) || (var_f13 = -var_f13, (var_f0 < var_f13))) {
        var_f0 = var_f13;
    }
    temp_f1 = *arg0 + var_f0;
    *arg0 = temp_f1;
    { f32 r; __asm__("abs.s %0, %1" : "=f"(r) : "f"(fparg0 - temp_f1)); return r; }
}
/* localdecomp:end func_004450C0 */
