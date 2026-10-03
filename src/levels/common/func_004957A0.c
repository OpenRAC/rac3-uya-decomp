#include "common.h"
typedef struct {
    u8 padding[0x10];
    s32 count;
    u8 pad14[0x4C];
    f32 value;
    u8 pad64[0x10];
    u8 flag;
    u8 pad75[0x2B];
    f32 base;
    f32 scale;
} State_004957A0;
extern s32 func_004950E8_004957A0(s32, s32);
extern s32 func_00513548_004957A0(s32, f32, f32);
extern s32 func_00512D70_004957A0(s32, s32);
void func_004957A0(State_004957A0 *state) {
    f32 value = state->value - state->base;
    s32 index;
    if (value < 0.0f) value = 0.0f;
    for (index = 0; index < state->count + 2; index++) {
        func_00513548_004957A0(func_004950E8_004957A0((s32)state, index), value, state->scale);
        func_00512D70_004957A0(func_004950E8_004957A0((s32)state, index), state->flag);
    }
}
