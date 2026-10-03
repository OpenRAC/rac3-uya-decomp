#include "common.h"

typedef struct {
    u8 reserved[0xA4];
    s32 field_A4;
    u8 reserved_A8[8];
    s32 field_B0;
} LeafState;

extern s32 D_001DFBC0;

void func_003C5640(s32 unused, LeafState *state) {
    s32 value = state->field_B0;
    if (value >= 3) return;
    if (value <= 0) return;
    state->field_B0 = 3;
    state->field_A4 = D_001DFBC0;
}
