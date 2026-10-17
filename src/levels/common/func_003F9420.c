#include "common.h"

extern u8 D_001D66B0[];
extern s32 func_0045D850(void *, s32, s32);
extern void func_004C0DD0(s32, s32, void *);
extern void func_00468230(void *, s32, void *, s32, s32, s32, s32, s32, s32, s32,
                          f32, f32, f32, f32, f32, f32, f32, f32);
extern void func_004680C8(void *, s32, f32);
extern void func_0044F860(void *);

void func_003F9420(void *self) {
    if (func_0045D850(self, -1, 0) != 0) {
        func_004C0DD0(0, 0, self);
        func_00468230(self, 31, D_001D66B0, 255, 180, 0, 0, 35, 0, 3,
                      3.0f, 6.0f, 3.0f, 6.0f, -1.0f, -1.0f, 1.0f, 1.0f);
        func_004680C8(self, 1, 0.0f);
        func_0044F860(self);
    }
}
