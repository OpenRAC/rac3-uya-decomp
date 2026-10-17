#include "common.h"

typedef struct { s32 id; s32 b; s32 c; } S_0053B368;
extern S_0053B368 D_00347A50[];

s32 func_0053B368(s32 id) {
    s32 i;
    for (i = 0; i < 40; i++) {
        if (D_00347A50[i].id == id) {
            D_00347A50[i].id = 0;
            return 1;
        }
    }
    return -1;
}
