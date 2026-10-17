#include "common.h"

extern s32 D_001D545C;
extern u8 D_001BBC40[][16];
extern u8 D_001A4C60[];

extern s32 func_00440760(void *a, s32 b, s32 c);

s32 func_003C4328(s32 unused, u8 *obj) {
    s32 i;
    s32 *p = (s32 *)(obj + 1856);
    for (i = 0; i < 4; i++, p++) {
        s32 a = p[-4];
        s32 b;
        if (a == -1) {
            continue;
        }
        b = p[0];
        if (b != -1 && !(D_001BBC40[D_001D545C][b] & 0x80)) {
            continue;
        }
        if (func_00440760(D_001A4C60, a, 0) != 0) {
            return i;
        }
    }
    return -1;
}
