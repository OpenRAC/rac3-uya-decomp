#include "common.h"

/* localdecomp:start func_004D21B0 */
extern s32 D_001DB910_003B6368;
/* The 16-byte .sdata declarations look small to gcc (no %hi/%lo split) but
   not to the assembler, which reaches them through lui, as Ps2EeAs did for
   symbols it had no size for yet; the other small ones go through $gp. */
extern s32 D_001E12A0_003B6368[4] __attribute__((section(".sdata")));
extern s32 D_001E12C8_003B6368[4] __attribute__((section(".sdata")));
extern s32 D_001E12F0_003B6368[4] __attribute__((section(".sdata")));
extern void func_0013CA20();
extern void func_0013CA28();
extern void func_0013B620_003B6368();
extern void func_0013C0B8(s32, s32, s32, s32, s32, s32, void *, long);
extern void func_004D21A0();

void func_004D21B0(s32 a) {
    s32 i;
    s32 *p;
    if (a >= 0 && a < D_001DB910_003B6368) {
        i = D_001E12C8_003B6368[a] * 4;
        p = (s32 *)((u8 *)D_001E12F0_003B6368 + i);
        *p = -1;
        func_0013CA20();
        func_0013C0B8(*(s32 *)((u8 *)D_001E12A0_003B6368 + i), 0, 0x400, 0, 0, 0, func_004D21A0, (long)p);
        func_0013CA28();
        func_0013B620_003B6368();
    }
}
/* localdecomp:end func_004D21B0 */
