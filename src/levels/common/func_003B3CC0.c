#include "common.h"

typedef struct {
    u8 pad[0x34];
    u16 h34;
    u8 pad36[0x32];
    s32 *w68;
} Moby_003B3CC0;

extern void func_00441FB8(Moby_003B3CC0 *, s32, s32);

void func_003B3CC0(Moby_003B3CC0 *m, s32 value) {
    m->w68[3] = value;
    func_00441FB8(m, 2, -1);
    m->h34 &= ~2;
}
