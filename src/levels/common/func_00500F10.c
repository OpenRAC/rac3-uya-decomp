#include "common.h"

/* localdecomp:start func_00500F10 */
extern u8 D_001A71C4[];
extern void func_004FC518(s32, s32);

void func_00500F10(s32 arg0)
{
    s32 mode;

    mode = 1;
    if (arg0 != 0) {
        mode = 2;
    }
    switch (D_001A71C4[0]) {
    case 0:
        func_004FC518(0, mode);
        break;
    case 3:
        func_004FC518(81, mode);
        break;
    case 1:
        func_004FC518(63, mode);
        break;
    }
}
/* localdecomp:end func_00500F10 */
