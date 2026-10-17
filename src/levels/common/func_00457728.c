#include "common.h"

typedef int u128_t __attribute__((mode(TI)));

extern u8 *func_00458650(u8 *);
extern void func_004585D0(u8 *, u8 *);
extern f32 func_0040BF38(u8 *);
extern f32 func_0040BF68(u8 *);
extern void func_00457C20(u8 *, u8 *);
extern void func_00458230(u8 *, u8 *);

s32 func_00457728(u8 *a, u128_t *v) {
    u8 *o;
    u8 *p;

    o = func_00458650(a);
    if (o == 0) {
        return 8;
    }
    p = o + 160;
    *(u128_t *)p = *v;
    func_004585D0(a, o);
    if (*(s32 *)(o + 56) & 0x400) {
        *(f32 *)(o + 176) = func_0040BF38(o + 160);
    } else {
        *(f32 *)(o + 176) = func_0040BF68(o + 160);
    }
    func_00457C20(a, o);
    func_00458230(a, o);
    return *(s32 *)(o + 148);
}
