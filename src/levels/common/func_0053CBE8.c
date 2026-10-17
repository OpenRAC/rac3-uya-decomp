#include "common.h"

typedef struct { u8 pad[49]; u8 b31; u8 pad2[18]; } S_0053CBE8;
extern S_0053CBE8 D_0033F460[];

s32 func_0053CBE8(void) {
    s32 i;
    for (i = 0; i < 50; i++) {
        if (D_0033F460[i].b31 == 0) {
            return i;
        }
    }
    return -1;
}
