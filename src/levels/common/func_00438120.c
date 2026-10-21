#include "common.h"

/* localdecomp:start func_00438120 */
extern void func_00438120(void);
extern void func_00438120();

extern void func_00437EF8();
extern void func_00437F80();
extern void func_004380C0();
s32 func_0043EA78_003BE340(s32, s32, s32, s32);      /* extern */
extern s32 D_001E0098;
extern s32 D_001E009C;
extern s32 D_001E00D4;

void func_00438120(void) {
    s32 var_a3;

    func_00437F80();
    func_00437EF8();
    var_a3 = 1;
    if (D_001E00D4 != 0) {
        D_001E00D4 = 0;
        var_a3 = 3;
    }
    D_001E0098 = func_0043EA78_003BE340(D_001E009C, D_001E0098, -1, var_a3);
    func_004380C0();
}
/* localdecomp:end func_00438120 */
