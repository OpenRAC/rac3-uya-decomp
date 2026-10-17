#include "common.h"

extern s32 func_00434640();

extern s32 D_002E9A30[];
extern s32 D_001DFFB8;
s32 func_00434640(u32 i) {
    s32 r = 0;
    if (i < 0x3C) {
        s32 v = D_002E9A30[i];
        if (v != 0) {
            D_001DFFB8 = v;
            r = 1;
        }
    }
    return r;
}
