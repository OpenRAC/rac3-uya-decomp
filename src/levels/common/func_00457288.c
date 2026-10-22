#include "common.h"

/* localdecomp:start func_00457288 */
extern s32 func_00457288(s32, s32, s32, s32, u8 *);
extern u8  D_001D6678[];
extern s32 D_001A7430[];

extern u8 D_001D6678[];
extern s32 D_001E02A0[8];
extern s32 D_001D6690;
extern s32 D_001D6694;
extern s32 D_001D4CEC;
extern s32 D_001D7DC8;
extern s32 D_001D7DC0;
extern s32 D_001D7DC4;
extern s32 D_001D7DCC;
s32 func_00457288(s32 screenId, s32 mode, s32 arg2, s32 arg3, u8 *outPtr) {
    s32 result;
    s32 flag;

    if (outPtr != 0) {
        *outPtr = 0;
    }
    result = (D_001D6690 == -2) ? 0 : -1;
    if (mode == 1) {
        result = (D_001D7DC8 < 8) ? result : -2;
    }
    do {
        flag = 0;
    } while (0);
    if (screenId >= 0) flag = D_001D6678[screenId];
    if (flag) {
        result = -3;
    }
    if (D_001A7430[0] == 0) {
        if ((D_001D6694 != 0) || ((D_001D4CEC & 1) == 0)) {
            result = -1;
        }
    }
    if (result == 0) {
        D_001D6690 = screenId;
        D_001D7DC0 = arg2;
        D_001D7DC4 = arg3;
        D_001D7DCC = (s32)outPtr;
        if (mode == 1) {
            D_001E02A0[D_001D7DC8++] = D_001D6694;
        }
    }
    return result;
}
/* localdecomp:end func_00457288 */
