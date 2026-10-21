#include "common.h"

/* localdecomp:start func_004DF4A0 */
extern u8 D_001A4BE0[];
extern char D_004DF4E0[];
extern void func_00402498(char *, s32);
void func_004DF4A0(void) {
    u8 *b = D_001A4BE0;
    if (*(s16 *)(b + 9170) == 0) {
        *(s16 *)(b + 9170) = 1;
        func_00402498(D_004DF4E0, *(s32 *)(b + 9664));
    }
}
/* localdecomp:end func_004DF4A0 */
