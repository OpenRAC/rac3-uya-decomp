#include "common.h"

typedef struct {
    u8 pad0[0x34];
    u16 x34;
} func_004DCED8_t;
extern func_004DCED8_t *D_001A71A0[];

void func_004DCED8(void) {
    D_001A71A0[0]->x34 &= ~1;
}
