#include "common.h"

extern u8 D_001A4BE0[];
extern f32 D_001DBFC0[2];
extern f32 D_001DBFD0[2];

s32 func_004E1470(void) {
    u8 *p = D_001A4BE0;
    u8 *q = *(u8 **)(p + 6848);
    s32 flag = 0;
    f32 f;
    s32 i;

    if (q != 0) {
        flag = q[35] == 0x21;
    }
    if (*(s32 *)(p + 9668) != 157) {
        if (!flag) {
            return 0;
        }
    }
    {
        u8 *g = D_001A4BE0;
        f = *(f32 *)(g + 3096);
        if (flag) {
            f = *(f32 *)(g + 6860);
        }
        if (*(s32 *)(g + 3084) == 0) {
            i = *(s16 *)(g + 3036);
            if (D_001DBFC0[i] <= f) {
                if (f <= D_001DBFD0[i]) {
                    return 1;
                }
            }
        }
    }
    return 0;
}
