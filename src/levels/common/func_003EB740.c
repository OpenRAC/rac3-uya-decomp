#include "common.h"
typedef struct {
    s32 f0;
    u8 pad4[24];
    s32 f28;
    u8 pad32[17];
    u8 f49;
    u8 pad50[18];
} S_003EB740;
extern S_003EB740 D_0033F460[];
s32 func_003EB740(s32 id) {
    s32 i;
    for (i = 0; i < 50; i++) {
        if (D_0033F460[i].f49 == 1 && D_0033F460[i].f28 == id) {
            return D_0033F460[i].f0;
        }
    }
    return -1;
}
