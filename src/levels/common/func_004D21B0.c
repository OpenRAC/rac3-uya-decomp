#include "common.h"

/* localdecomp:start func_004D21B0 */
extern s32 D_001DB910;
/* indexed alongside the two 40-byte tables below */
extern s32 D_001E12A0[10];
extern s32 D_001E12C8[10];
extern s32 D_001E12F0[10];
extern void func_0013CA20();
extern void func_0013CA28();
extern void func_0013B620_003B6368();
extern void func_0013C0B8(s32, s32, s32, s32, s32, s32, void *, long);
extern void func_004D21A0();

void func_004D21B0(s32 a) {
    s32 i;
    s32 *p;
    if (a >= 0 && a < D_001DB910) {
        i = D_001E12C8[a];
        p = &D_001E12F0[i];
        *p = -1;
        func_0013CA20();
        func_0013C0B8(D_001E12A0[i], 0, 0x400, 0, 0, 0, func_004D21A0, (long)p);
        func_0013CA28();
        func_0013B620_003B6368();
    }
}
/* localdecomp:end func_004D21B0 */
