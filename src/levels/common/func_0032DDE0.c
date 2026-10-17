#include "common.h"

typedef struct {
    u8 pad0[0x20];
    u8 x20;
} func_0032DDE0_t;

void func_0032DDE0(func_0032DDE0_t *a) {
    if (a->x20 < 8) {
        a->x20 = 8;
    }
}
