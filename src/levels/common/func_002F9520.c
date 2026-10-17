#include "common.h"
s32 func_002F9520(u8 *a0) {
    u16 v = *(u16 *)(a0 + 170);
    if ((u32)(v - 13) < 7) {
        return (s16)v - 13;
    }
    switch ((s16)v) {
    case 7516:
        return 7;
    case 7517:
        return 8;
    case 7077:
        return 9;
    }
    return 0;
}
