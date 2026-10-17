#include "common.h"

extern s32 func_00432730();

s32 func_00432730(s32 *p) {
    s32 n = 8;
    if (p[0] != 0) {
        do {
            n += 8;
            n += p[1];
            p += 4;
            n = (n + 3) & ~3;
        } while (p[0] != 0);
    }
    return n + 8;
}
