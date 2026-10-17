#include "common.h"

typedef struct {
    u8 pad0[0xC];
    f32 fC;
} S_31F6C8_Res;

typedef struct {
    u8 pad0[0x10];
    u8 sub[0x10];
    u8 b20;
    u8 pad21[0xCF];
    f32 fF0;
    f32 fF4;
} S_31F6C8;

extern void func_0031F858(S_31F6C8 *);
extern S_31F6C8_Res *func_00469378(void *, s32, s32, s32);
extern f32 func_0040CEC8(f32, f32);
extern void func_0031F768(S_31F6C8 *);

void func_0031F6C8(S_31F6C8 *self) {
    S_31F6C8_Res *r;
    if (self->b20) {
        return;
    }
    func_0031F858(self);
    r = func_00469378(self->sub, 15, 0, 0);
    if (r) {
        r->fC = 157500.0f;
    }
    self->fF0 = func_0040CEC8(self->fF0, 0.0349065885f);
    self->fF4 = func_0040CEC8(self->fF4, 0.130899698f);
    func_0031F768(self);
}
