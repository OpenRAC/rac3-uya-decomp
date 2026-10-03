#include "common.h"
typedef struct {
    u8 padding[0x18];
    f32 f18;
    s32 f1C, f20;
    f32 f24;
    s8 b28;
    u8 pad29[3];
    s32 f2C;
    u8 pad30[0x50];
    s32 f80, f84;
} State_004CB610;
typedef struct {
    u8 padding[0x30];
    f32 matrix[4][4];
    f32 values[4];
} Matrix_004CB610;
typedef struct { f32 first[3]; f32 second[3]; } Vector_004CB610;
extern void func_004CB730_004CB610(Matrix_004CB610 *, s32, f32, f32, f32, f32, f32);
extern void func_004CB768_004CB610(Vector_004CB610 *, s32, f32, f32);
void func_004CB610(State_004CB610 *state) {
    f32 value;
    state->f18 = 0;
    state->b28 = 0;
    value = state->f18;
    state->f2C = 0;
    state->f80 = 0;
    state->f24 = 0.005f;
    func_004CB730_004CB610((Matrix_004CB610 *)state, 0, value, value, value, value, value);
    func_004CB730_004CB610((Matrix_004CB610 *)state, 1, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    state->f84 = 2;
    func_004CB768_004CB610((Vector_004CB610 *)state, 0, value, value);
    state->f20 = 0;
    state->f1C = 1;
}
