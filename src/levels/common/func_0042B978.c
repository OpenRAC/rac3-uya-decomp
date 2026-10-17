#include "common.h"
typedef struct {
    u8 pad0[36];
    s32 flag;
    u8 pad1[1000];
    s32 val;
} St0042B978;
extern St0042B978 D_001F4020;
extern s32 D_001D545C;
extern s32 func_0042B550(s32);
s32 func_0042B978(void) {
    if (D_001F4020.val >= 60) {
        D_001F4020.val = 59;
    }
    if (func_0042B550(D_001F4020.val)) {
        D_001F4020.flag = 1;
    } else {
        D_001F4020.flag = 0;
    }
    if (D_001F4020.val == 0 && D_001D545C != 0) {
        D_001F4020.flag = 0;
    }
    return D_001F4020.flag != 0;
}
