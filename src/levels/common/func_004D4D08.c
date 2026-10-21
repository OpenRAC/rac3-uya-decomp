#include "common.h"

/* localdecomp:start func_004D4D08 */
extern void func_00402A10(s32);

extern void func_004D2370(s32, s32);
extern void func_00402A10(s32);
extern s32 D_001E1370[];
s32 func_004D4D08(void) {
    func_004D2370(0, 0);
    func_00402A10(6);
    D_001E1370[0] = 300;
    return 1;
}
/* localdecomp:end func_004D4D08 */
