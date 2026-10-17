#include "common.h"
typedef struct { u8 pad[190]; u8 flags; } S452;
void func_00452F40(S452 *p, s32 on) {
    if (on) p->flags |= 4;
    else p->flags &= ~4;
}
