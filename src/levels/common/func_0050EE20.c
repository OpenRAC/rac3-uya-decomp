#include "common.h"
extern u8 D_001439F4[];
extern u8 D_001A71C4[];
s32 func_0050EE20(s32 a, s32 i) {
    if (D_001439F4[0] != 0 && D_001A71C4[0] == 0) {
        switch (a) {
        case 0x40: return 0x44;
        case 4: return 1;
        case 8: return 2;
        }
    }
    return a;
}
