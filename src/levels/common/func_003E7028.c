#include "common.h"

typedef struct {
    u8 pad[80];
    u8 *obj;
    u8 pad2[1120 - 84];
} Slot;

extern Slot D_001E2AC0[];

void func_003E7028(s32 i) {
    Slot *s = &D_001E2AC0[i];
    u8 *o = s->obj;
    if (*(s16 *)(o + 134) == 0) {
        *(*(u8 **)(o + 112) + 345) = 1;
    }
}
