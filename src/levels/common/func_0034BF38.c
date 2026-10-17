#include "common.h"

typedef struct {
    u8 pad0[24];
    s32 x18;
    u8 pad1[20];
} S_27F600;

extern S_27F600 D_0027F600[];

s32 func_0034BF38(s32 id) {
    s32 r = -1;
    s32 i;

    for (i = 0; i < 30; i++) {
        if (D_0027F600[i].x18 == id) {
            r = i;
            break;
        }
    }
    return r;
}
