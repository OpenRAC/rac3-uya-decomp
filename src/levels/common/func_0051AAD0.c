#include "common.h"
typedef struct Object_0051AAD0 Object_0051AAD0;
typedef struct {
    u8 padding[8];
    void (*activate)(Object_0051AAD0 *, s32);
    void (*reset)(Object_0051AAD0 *);
} Vtable_0051AAD0;
struct Object_0051AAD0 { s32 state; Vtable_0051AAD0 *vtable; };
typedef struct {
    u8 padding[0xC];
    s32 flags;
    u8 reserved[0x38];
    u16 value;
    u8 pad4A[4];
    s8 mode;
    u8 pad4F;
    Object_0051AAD0 *object;
} State_0051AAD0;
void func_0051AAD0(State_0051AAD0 *state, s32 value) {
    Object_0051AAD0 *object;
    if (state->value != value) {
        state->value = value;
        if ((u16)value != 0) {
            object = state->object;
            if (object != 0) {
                if ((object->state ^ 4) == 0) {
                    object->vtable->reset(object);
                }
                if (state->flags & 0x8000) {
                    state->mode = 4;
                    return;
                }
                state->object->vtable->activate(state->object, value - 1);
            }
        }
    }
}
