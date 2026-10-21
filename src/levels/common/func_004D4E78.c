#include "common.h"

/* localdecomp:start func_004D4E78 */
extern s32 func_004D4ED8();
extern void func_004D56C8();
void func_004D4E78(u8 *p) {
    s32 ok = 0;
    switch (*(s16 *)(p + 0xAA)) {
    case 0x19E9:
        ok = 1;
        *(void **)(p + 0x64) = func_004D4ED8;
        break;
    case 0x1D98:
        ok = 1;
        *(void **)(p + 0x64) = func_004D56C8;
        break;
    }
    if (ok) *(u16 *)(p + 0x34) &= ~2;
    else *(u16 *)(p + 0x34) |= 2;
}
/* localdecomp:end func_004D4E78 */
