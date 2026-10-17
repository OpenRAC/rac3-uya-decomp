#include "common.h"

typedef int u128 __attribute__((mode(TI)));

typedef struct {
    u8 pad0[0xA0];
    u128 xA0;
    u8 padB0[0x1DC0 - 0xB0];
    u128 x1DC0;
    u8 pad1DD0[0x2348 - 0x1DD0];
    s32 x2348;
    s32 x234C;
} func_0061EBD0_t;

void func_0061EBD0(func_0061EBD0_t *a) {
    a->x2348 = 1;
    a->x1DC0 = a->xA0;
    a->x234C = 1;
}
