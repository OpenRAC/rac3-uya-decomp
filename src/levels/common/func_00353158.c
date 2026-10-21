#include "common.h"

/* localdecomp:start func_00353158 */
typedef struct {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} __attribute__((aligned(16))) S_353158v;

extern s32 func_00440878(s32, s32);
extern void func_00441C78(u8 *, s32, s32, s32);
extern f32 func_00443140(void *, s32, s32, f32);
extern void func_00441FB8(u8 *, s32, s32);
extern void func_00407180(u8 *, void *, void *, s32, s32, s32, s32, s32, s32, s32);

void func_00353158(u8 *p, S_353158v *src) {
    S_353158v tmp;
    u8 *q;
    u8 b;
    u16 h;
    u8 *pos;

    pos = p + 0x10;
    tmp = *src;
    *(S_353158v *)(p + 0x10) = tmp;
    h = *(u16 *)(p + 0x34) & 0xFFBC;
    *(u16 *)(p + 0x34) = h;
    q = *(u8 **)(p + 0x24);
    b = p[0x43];
    *(u16 *)(p + 0x34) = h | (*(u16 *)(q + 0x44) & 0x1000);
    *(s32 *)(p + 0x98) = *(s32 *)(q + 0x10);
    if (b != 0) {
        func_00441C78(p, 0, func_00440878(0, 10), 0);
    }
    *(f32 *)(p + 0x18) = func_00443140(pos, 0, 0, 0.5f);
    if (p[0x95] == 9) {
        func_00441FB8(p, 24, -1);
    } else {
        func_00441FB8(p, 2, 1);
    }
    p[0x31] = 0;
    *(u16 *)(p + 0x34) |= 1;
    func_00407180(p, p + 0x10, p + 0xF0, 0, 2, 3, 45, 45, 0x80FF40, 0x108F10);
}
/* localdecomp:end func_00353158 */
