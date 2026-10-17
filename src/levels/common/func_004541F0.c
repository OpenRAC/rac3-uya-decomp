#include "common.h"

typedef struct { s32 f0; s32 f4; u8 pad[0xA428]; } S_4541F0;
extern S_4541F0 D_002D1710[];
extern s32 D_001D6780;

void func_004541F0(void) {
    s32 i;
    D_001D6780 = 0;
    for (i = 0; i < 2; i++) {
        D_002D1710[i].f4 = -1;
        D_002D1710[i].f0 = 0;
    }
}
