#include "common.h"

/* localdecomp:start func_005D99E8 */
extern u8 D_001D8194;
extern s32 func_0060F870(void);
extern void func_0060F828(s32);
extern void func_0060E900(s32, s32, s32);

void func_005D99E8(s32 a0) {
    s32 old;
    if (D_001D8194 != 0) {
        old = func_0060F870();
        if (a0 != -1) {
            func_0060F828(a0);
        }
        func_0060E900(0x50000, 1, 0);
        func_0060E900(0x50001, 1, 0);
        func_0060E900(0x50002, 1, 0);
        func_0060E900(0x50003, 1, 0);
        func_0060E900(0x50004, 1, 0);
        func_0060E900(0x50005, 1, 0);
        if (a0 != -1) {
            func_0060F828(old);
        }
    }
}
/* localdecomp:end func_005D99E8 */
