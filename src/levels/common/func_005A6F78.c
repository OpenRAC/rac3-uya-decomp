#include "common.h"
typedef struct { s32 a; s32 b; } Pair;
typedef struct { u8 pad[0x24DE0]; Pair arr[3]; } Big;
extern Big *D_001D7340;
void func_005A6F78(u32 a0) {
    if (a0 < 3) {
        D_001D7340->arr[a0].a = 0;
        D_001D7340->arr[a0].b = 0;
    }
}
