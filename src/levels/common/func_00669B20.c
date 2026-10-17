#include "common.h"

typedef struct { s32 id; u8 pad[12]; } S_00669B20;
extern S_00669B20 D_0033B9F0[];

s32 func_00669B20(s32 id) {
    s32 i;
    for (i = 0; i < 10; i++) {
        if (D_0033B9F0[i].id == id) {
            return i;
        }
    }
    return -1;
}
