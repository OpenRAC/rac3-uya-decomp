#include "common.h"

typedef struct {
    u8 pad0[0x34];
    u16 x34;
} func_004DCEC0_t;
extern func_004DCEC0_t *D_001A71A0[];

void func_004DCEC0(void) {
    D_001A71A0[0]->x34 |= 1;
}
