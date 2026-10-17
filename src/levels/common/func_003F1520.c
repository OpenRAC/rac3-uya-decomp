#include "common.h"

typedef struct {
    u8 pad[80];
    u8 *obj;
    u8 pad2[1120 - 84];
} Slot;

extern Slot D_001E2AC0[];

void func_003F1520(s32 i) {
    Slot *s = &D_001E2AC0[i];
    *(s16 *)(s->obj + 126) = 1;
    *(s->obj + 125) = 0;
}
