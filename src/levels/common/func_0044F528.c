#include "common.h"
extern u8 D_001BBB18[][8];
s32 func_0044F528(s32 a0) {
    u8 *p = D_001BBB18[a0];
    s32 n = 0;
    s32 i;
    for (i = 7; i >= 0; i--) {
        if (*p++) n++;
    }
    if (n < 0) n = 0;
    if (n > 40) n = 40;
    return n;
}
