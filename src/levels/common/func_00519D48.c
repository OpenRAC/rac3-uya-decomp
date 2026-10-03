#include "common.h"

typedef struct Object_00519D48 Object_00519D48;
typedef struct {
    u8 padding[0x20];
    void (*get_vector)(Object_00519D48 *, s32, f32 *, s32);
} Vtable_00519D48;
typedef struct {
    s32 *entries[1];
    u8 padding[0x44];
    s32 count;
} List_00519D48;
struct Object_00519D48 {
    u8 padding[8];
    Vtable_00519D48 *vtable;
    u8 reserved[0x20];
    List_00519D48 *list;
};
extern void func_00519608_00519D48(Object_00519D48 *, f32 *);
extern s32 func_00519AA8_00519D48(void *, s32);
extern void func_00519658_00519D48(f32, f32, f32, f32);
extern void func_00519598_00519D48(void *, s32);
void func_00519D48(Object_00519D48 *self, s32 mode) {
    f32 vector[4];
    s32 index;
    self->vtable->get_vector(self, mode, vector, 1);
    func_00519608_00519D48(self, vector);
    if (func_00519AA8_00519D48(self, 1)) {
        func_00519658_00519D48(vector[0], vector[1], vector[2], vector[3]);
    }
    for (index = 0; index < self->list->count; index++) {
        func_00519598_00519D48(((s32 **)self->list)[index], mode);
    }
    if (func_00519AA8_00519D48(self, 1)) {
        func_00519658_00519D48(0.0f, 0.0f, 1.0f, 1.0f);
    }
}
