#include "common.h"

typedef struct { s32 id; u8 pad[44]; } S_00668F68;
extern S_00668F68 D_0033BA90[];

s32 func_00668F68(s32 id) {
    s32 i;
    for (i = 0; i < 40; i++) {
        if (D_0033BA90[i].id == id) {
            return i;
        }
    }
    return -1;
}
