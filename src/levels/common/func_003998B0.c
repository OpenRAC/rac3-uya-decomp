#include "common.h"

typedef struct {
    u8 pad[0x68];
    u8 *w68;
} Moby_003998B0;

extern u8 D_001A4C60[];
extern s32 func_0042DA90(void *, s32, s32);

s32 func_003998B0(Moby_003998B0 *m) {
    s32 r;
    s32 id = *(s32 *)(m->w68 + 1272);
    if (id == -1) {
        r = 0;
    } else {
        r = func_0042DA90(D_001A4C60, id, 0) != 0;
    }
    return r;
}
