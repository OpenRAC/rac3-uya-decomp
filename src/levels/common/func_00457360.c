#include "common.h"

/* localdecomp:start func_00457360 */
extern s32 D_001D6690;
extern s32 D_001D6694;
extern s32 D_001A7430[];
extern s32 D_001E02A0[8];
extern s32 D_001D7DC8;
extern s32 D_001D7DC0;
extern s32 D_001D7DC4;
extern s32 D_001D7DCC;
s32 func_00457360(s32 screenId, s32 arg1) {
    s32 result;
    if (D_001D6690 != -2) result = 1; else result = 0;
    if (D_001D7DC8 == 0) result = 1;
    if (D_001D6694 != 4) {
        if (D_001A7430[0] == 0) result = -1;
    }
    if (result == 0) {
        s32 i = D_001D7DC8 - 1;
        D_001D7DC0 = screenId;
        D_001D7DC4 = arg1;
        D_001D7DC8 = i;
        D_001D6690 = D_001E02A0[i];
        D_001D7DCC = 0;
    }
    return result;
}
/* localdecomp:end func_00457360 */
