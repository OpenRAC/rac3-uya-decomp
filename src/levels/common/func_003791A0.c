#include "common.h"

typedef struct {
    u8 pad[0x68];
    s32 *w68;
} Moby_003791A0;

extern void func_004626C8(Moby_003791A0 *, s32);

void func_003791A0(Moby_003791A0 *m, s32 value, s32 force) {
    s32 *p = m->w68;
    if (p == 0) return;
    if (force == 0 && *p != value) return;
    *p = value;
    func_004626C8(m, force);
}
