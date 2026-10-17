#include "common.h"
typedef struct { u8 pad[1140]; s32 a; s32 b; } S61E;
s32 func_0061EB48(S61E *p) {
    if (p->a == 2) return p->b;
    return -1;
}
