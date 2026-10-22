#include "common.h"

/* localdecomp:start func_005429B0 */
typedef struct { s32 w[4]; } Q_005429B0;
extern void func_00542F90(s32);

void func_005429B0(u8 *a0) {
    u8 *p = *(u8 **)(*(u8 **)(a0 + 0x68) + 0x384);
    __asm__("sq $0,%0" : "=m"(*(Q_005429B0 *)(p + 0x270)));
    *(f32 *)(p + 0x308) = 60.0f;
    *(f32 *)(p + 0x30C) = 60.0f;
    *(s32 *)(p + 0x310) = 0;
    func_00542F90(*(s32 *)(p + 0x2D0));
}
/* localdecomp:end func_005429B0 */
