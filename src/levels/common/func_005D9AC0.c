#include "common.h"

/* localdecomp:start func_005D9AC0 */
extern u8 D_001D8194;
extern s32 func_0060F870(void);
extern void func_0060F828(s32);
extern void func_0060E900(s32, s32, s32);

void func_005D9AC0(s32 mode) {
    s32 old;

    if (D_001D8194 != 0) {
        old = func_0060F870();
        if (mode != -1) {
            func_0060F828(mode);
        }
        func_0060E900(0x50000, 1, 1);
        func_0060E900(0x50001, 1, 1);
        func_0060E900(0x50002, 1, 1);
        func_0060E900(0x50003, 1, 1);
        func_0060E900(0x50004, 1, 1);
        func_0060E900(0x50005, 1, 1);
        if (mode != -1) {
            func_0060F828(old);
        }
    }
}
/* localdecomp:end func_005D9AC0 */
