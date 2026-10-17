#include "common.h"

typedef struct {
    u8 pad0[0x68];
    s32 x68;
} func_005606A8_t;

s32 func_005606A8(func_005606A8_t *a, s32 *b, s32 *c) {
    s32 v = a->x68;
    *c = 16;
    *b = v;
    return 0;
}
