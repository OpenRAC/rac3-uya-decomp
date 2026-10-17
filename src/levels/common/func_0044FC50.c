#include "common.h"
typedef struct {
    char pad0[58];
    s16 bit;
    char pad60[13];
    u8 active;
    u16 mask;
} Unk44FC50;
s32 func_0044FC50(s32 a0, Unk44FC50 *p) {
    if (p->active) {
        if (p->mask) {
            if (p->bit != -1 && ((p->mask >> p->bit) & 1)) {
                return 1;
            }
        }
    }
    return 0;
}
