#include "common.h"

typedef struct {
    u8 pad[1128];
    s32 b[5];
    s32 a[5];
} S42B3C8;

extern S42B3C8 D_001F4020;
extern s32 func_0042B360(s32);
extern void func_0042B468(s32, s32);

s32 func_0042B3C8(void) {
    s32 i = func_0042B360(1);

    if (i != 0) {
        return i;
    }
    for (i = 1; i < 5; i++) {
        if (!(D_001F4020.a[i] & 0x1000) && D_001F4020.b[i] != 0) {
            break;
        }
    }
    func_0042B468(0, i);
    return i;
}
