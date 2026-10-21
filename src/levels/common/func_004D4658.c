#include "common.h"

/* localdecomp:start func_004D4658 */
extern s8 D_001E1349[];

void func_004D4658(void) {
    s32 var_v1;
    s8 *var_v0;

    var_v1 = 9;
    var_v0 = D_001E1349;
    do {
        *var_v0 = 0;
        var_v1 -= 1;
        var_v0 -= 1;
    } while (var_v1 >= 0);
}
/* localdecomp:end func_004D4658 */
