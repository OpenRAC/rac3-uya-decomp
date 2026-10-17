#include "common.h"

extern u8 D_001A4BE0[];

s32 func_004E2EC8(s32 id) {
    u8 *p;
    s32 on;
    s32 r;

    p = D_001A4BE0;
    on = 0;
    if (*(s32 *)(p + 6948) != 0) {
        on = 1;
    }
    switch (id) {
    case 44:
        if (on) {
            return 48;
        }
        break;
    case 7:
        if (on) {
            return 47;
        }
        break;
    case 1:
        if (on) {
            r = 63;
            if (*(s32 *)(p + 6928) == 0) {
                r = 49;
            }
            return r;
        }
        break;
    }
    return id;
}
