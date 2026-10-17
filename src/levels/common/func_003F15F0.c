#include "common.h"

typedef struct {
    u8 pad[292];
    u8 *obj;
    u8 pad2[1120 - 296];
} Slot;

extern Slot D_001E2AC0[];

void func_003F15F0(s32 i) {
    Slot *s = &D_001E2AC0[i];
    u8 *o = s->obj;
    if (o != 0) {
        *(s32 *)(o + 152) = *(s32 *)(*(u8 **)(o + 36) + 16);
    }
}
