#include "common.h"

/* localdecomp:start func_004AB708 */
extern s16 D_0016C5A0[];
extern s32 D_001DF9C4;
extern void func_00401848(void);
extern void func_004010D0(s32);

void func_004AB708(void) {
    switch (D_0016C5A0[0]) {
    case 0:
    case 3:
        func_00401848();
        break;
    case 1:
        D_001DF9C4 = 127;
        func_004010D0(0);
        break;
    }
}
/* localdecomp:end func_004AB708 */
