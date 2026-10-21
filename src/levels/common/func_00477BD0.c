#include "common.h"

/* localdecomp:start func_00477BD0 */
extern s32 D_001D80A0;
extern s32 func_00477DE8(s32 a0);
extern s32 func_00512078(s32 a0);
extern void func_00512AB0(s32 a0, s32 a1, s32 a2);
s32 func_00477BD0(void) {
    if (func_00512078(func_00477DE8(0)) != 0) {
        if (D_001D80A0 != 0) func_00512AB0(0x90000, 1, 1);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_00477BD0 */
