#include "common.h"

typedef struct {
    u8 pad0[9048];
    s32 hist0[8];
    s32 hist1[8];
    s32 index;
    s32 count;
    u8 pad1[9520 - 9120];
    u8 *target;
} Self_65EAF8;

extern void func_005B6428(void *a, f32 *out);
extern void func_005B83E8(f32 *v, s32 *out);
extern void func_005B84D0(u8 *target, s32 *out);

void func_0065EAF8(Self_65EAF8 *self) {
    f32 v[4];
    if (*(s16 *)(*(u8 **)(self->target + 80) + 134) == 33) {
        return;
    }
    func_005B6428(self->target + 896, v);
    func_005B83E8(v, &self->hist1[self->index]);
    func_005B84D0(self->target, &self->hist0[self->index]);
    self->index = (self->index + 1) % 8;
    self->count++;
    if (self->count > 8) {
        self->count = 8;
    }
}
