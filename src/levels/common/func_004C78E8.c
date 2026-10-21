#include "common.h"

/* localdecomp:start func_004C78E8 */
u8 *func_004C78E8(u8 *s)
{
    s32 i;
    s32 *src;
    s32 a, b;

    *(s32 *)(s + 0x10) += (s32)s;
    *(s32 *)(s + 0x14) += (s32)s;
    *(s32 *)(s + 0x18) += (s32)s;
    *(s32 *)(s + 0x1C) += (s32)s;
    if (*(s32 *)(s + 0x20) != 0) {
        *(s32 *)(s + 0x20) += (s32)s;
    }
    *(f32 *)(s + 0xC) = *(f32 *)(s + 0xC) * 0.0032116016f;
    src = *(s32 **)(s + 0x18);
    for (i = 0; i < *(s16 *)(s + 6); i++) {
        s32 x0 = src[0];
        s32 x1 = src[1];
        s32 x2 = src[2];
        s32 x3 = src[3];
        *(s16 *)(*(u8 **)(s + 0x18) + i * 16 + 0xA) = x0 >> 4;
        __asm__("plzcw %0, %1" : "=r"(a) : "r"(x2));
        *(s16 *)(*(u8 **)(s + 0x18) + i * 16 + 0x8) = x1 >> 4;
        __asm__("plzcw %0, %1" : "=r"(b) : "r"(x3));
        *(s16 *)(*(u8 **)(s + 0x18) + i * 16 + 0xC) = 30 - a;
        *(s16 *)(*(u8 **)(s + 0x18) + i * 16 + 0xE) = 30 - b;
        *(long *)(*(u8 **)(s + 0x18) + i * 16) = 0;
        src += 4;
    }
    return s;
}
/* localdecomp:end func_004C78E8 */
