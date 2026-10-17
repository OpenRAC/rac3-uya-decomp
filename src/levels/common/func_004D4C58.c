#include "common.h"

typedef struct { u8 p0[0x44]; s16 n; u8 p1[0x15A]; void *slot[1]; } S_B7288;
extern S_B7288 D_001E6E00;

extern u32 D_001E009C;
extern u32 D_001E00A0;
void func_004D4C58(void (*cb)(u32)) {
    u32 p;
    s32 i;
    for (p = D_001E009C; p != D_001E00A0; p += 0x100) {
        cb(p);
    }
    for (i = 0; i < D_001E6E00.n; i++) {
        if (D_001E6E00.slot[i] != 0) {
            ((void (*)(void *))cb)(D_001E6E00.slot[i]);
        }
    }
}
