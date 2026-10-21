#include "common.h"

/* localdecomp:start func_004D38E8 */
extern s32 D_001DFBC4;

extern u8 D_001D5571;
s32 func_004AC588_003B7AA0(s32);                         /* extern */
extern s32 D_001DFBC4;
typedef struct { u8 pad0[0x7]; s8 f7; } S_001CCFD0_003B7AA0_003B7AA0;
extern S_001CCFD0_003B7AA0_003B7AA0 D_001CCFD0[];

void func_004D38E8(void) {
    if (D_001DFBC4 == 1) {
        if (D_001D5571 == 0) {
            D_001CCFD0->f7 = 0;
            if ((func_004AC588_003B7AA0(1) == 0) && (func_004AC588_003B7AA0(2) == 0) && (func_004AC588_003B7AA0(3) == 0) && (func_004AC588_003B7AA0(4) == 0) && (func_004AC588_003B7AA0(5) == 0)) {
                func_004AC588_003B7AA0(6);
            }
            D_001CCFD0->f7 = 1;
        }
    }
}
/* localdecomp:end func_004D38E8 */
