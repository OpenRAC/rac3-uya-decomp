#include "common.h"

/* localdecomp:start func_00500F98 */
extern u8 D_001A4BE0[];
extern void func_004E6CB0(void);
extern void func_004FC518(s32, s32);

s32 func_00500F98(void) {
    u8 *g = D_001A4BE0;
    s32 mode = *(s32 *)(g + 9668);

    if (!((u32)(mode - 2) < 2 || mode == 0)) {
        return 0;
    }
    if (g[9705] == 0) {
        return 0;
    }
    if (*(s32 *)(g + 472) >= 6) {
        return 0;
    }
    if (!(*(f32 *)(g + 10296) < 0.7f)) {
        return 0;
    }
    if (g[9708] != 0) {
        return 0;
    }
    func_004E6CB0();
    *(s32 *)(g + 3716) = 2;
    func_004FC518(34, 1);
    return 1;
}
/* localdecomp:end func_00500F98 */
