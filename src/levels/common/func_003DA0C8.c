#include "common.h"

typedef int u128_t __attribute__((mode(TI)));

extern u8 *func_0042EDB0(s32, s32);
extern void func_00432200(u8 *);

u8 *func_003DA0C8(u8 *parent, s32 oclass)
{
    u8 *obj = func_0042EDB0(oclass, 128);

    if (obj != 0) {
        *(u16 *)(obj + 50) = 255;
        obj[49] = 1;
        *(f32 *)(obj + 44) *= *(f32 *)(parent + 44) / *(f32 *)(*(u8 **)(parent + 36) + 36);
        *(u128_t *)(obj + 16) = *(u128_t *)(parent + 16);
        *(u128_t *)(obj + 240) = *(u128_t *)(parent + 240);
        *(long *)(obj + 56) = *(long *)(parent + 56);
        *(u16 *)(obj + 52) = 0;
        func_00432200(obj);
        return obj;
    }
    return 0;
}
