#include "common.h"

typedef struct {
    s32 type;
    s8 padding[8];
    s32 field_C, field_10, field_14, field_18;
} State_00490B98;

s32 func_00490B98(State_00490B98 *state, s32 first, s32 second, s32 third, s32 fourth) {
    s32 result = 0;
    s32 type = state->type;
    if ((type ^ 2) == 0 || (type ^ 1) == 0 || (type ^ 8) == 0) {
        state->field_C = first;
        state->field_10 = second;
        state->field_18 = third;
        state->field_14 = fourth;
        result = 1;
    }
    return result;
}
