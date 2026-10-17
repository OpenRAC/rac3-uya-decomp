#include "common.h"
extern u8 D_001A4BE0[];
extern void func_004C5178(void);
void func_004C4FF0(void) {
    u8 *p = D_001A4BE0;
    if (*(s32 *)(p + 4648) != 127 || *(u8 *)(p + 9700) == 3) {
        func_004C5178();
    }
}
