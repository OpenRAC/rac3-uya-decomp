#include "common.h"

/* localdecomp:start func_00416968 */
typedef struct {
    u8 b0;
    u8 pad[239];
} E_00416968;
extern u8 D_001425C0[];
extern E_00416968 D_002C5640[];
extern s32 func_00416878(s32);
extern s32 func_00416920(s32);
s32 func_00416968(s32 a0) {
    if (a0 == 9) {
        return 0;
    }
    if (a0 == 3) {
        return 0;
    }
    if (a0 == 2) {
        return 0;
    }
    if ((u32)(a0 - 36) < 3) {
        return 1;
    }
    if (func_00416878(a0)) {
        return 0;
    }
    if (D_002C5640[D_001425C0[a0]].b0) {
        return 1;
    }
    return func_00416920(a0) != 0;
}
/* localdecomp:end func_00416968 */
