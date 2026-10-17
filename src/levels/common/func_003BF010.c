#include "common.h"

typedef struct {
    u8 pad[80];
    u8 *obj;
    u8 pad2[1120 - 84];
} Slot;

extern Slot D_001E1380[];

void func_003BF010(s32 i, f32 v) {
    Slot *s = &D_001E1380[i];
    u8 *o = s->obj;
    if (*(s16 *)(o + 134) == 0) {
        *(f32 *)(*(u8 **)(o + 112) + 620) = v;
    }
}
