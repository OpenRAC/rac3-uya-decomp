#include "common.h"

typedef struct {
    u8 pad[8];
    s32 x8;
} S_142660;

extern S_142660 D_00142660;
extern s32 D_002AC2C0[];

s32 func_003183C8(void) {
    S_142660 *g = &D_00142660;
    s32 *t;
    s32 r = 0;
    s32 i = 0;

    for (t = D_002AC2C0; i < 19; i++, t++) {
        if (g->x8 < *t) break;
        if (g->x8 == *t) {
            r = 1;
            break;
        }
    }
    return r;
}
