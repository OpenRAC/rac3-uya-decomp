#include "common.h"

extern void func_0047F900(u8 *, s32, s32);
extern void func_00421CA0(u8 *);
extern s32 func_00421C80(u8 *);
extern void func_004233E0(u8 *);

void func_00421DA8(u8 *self) {
    u8 *v;

    if (self == 0) {
        return;
    }
    if (self[32] == 254) {
        return;
    }
    if (self[32] == 253) {
        return;
    }
    v = *(u8 **)(self + 104);
    func_0047F900(self, 1, -1);
    *(u16 *)(self + 52) &= 0xFFBE;
    *(u16 *)(self + 52) |= *(u16 *)(*(u8 **)(self + 36) + 68) & 0x1000;
    *(s32 *)(self + 152) = *(s32 *)(*(u8 **)(self + 36) + 16);
    self[168] = 255;
    func_00421CA0(self);
    *(f32 *)(v + 48) = 1.0f;
    *(u16 *)(self + 52) |= 0x1000;
    if (func_00421C80(self) != 0) {
        func_004233E0(self);
    }
}
