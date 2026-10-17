#include "common.h"
typedef struct { u8 pad[0xAA]; s16 t; } S639;
s32 func_00639598(s32 unused, S639 *p) {
    if (p == 0) return 0;
    return p->t == 0x18AB;
}
