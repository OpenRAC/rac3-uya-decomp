#include "common.h"

/* localdecomp:start func_003D6578 */
typedef int s128_3D6578 __attribute__((mode(TI)));
extern void func_0044DF40(f32 *a0, f32 *a1, s32 a2);
extern u8 *func_00435E70(s32 a0, s32 a1);
extern void func_0040C0F0(void *a0, void *a1, f32 s);
extern f32 func_0040C490(f32 y, f32 x);
extern f32 func_0040CEC8(f32 a, f32 b);
extern f32 func_0040BF68(f32 *a0);
extern void func_0040C638(void *a0, void *a1);
extern void func_00438908(u8 *a0, s32 a1, s32 a2, s32 a3);
extern s32 func_004C4A18(u8 *a0, f32 x, f32 y, f32 z, s32 a1);
u8 *func_003D6578(s32 a0, f32 *pos, f32 *dir) {
    f32 tmp[4];
    f32 tmp2[4];
    u8 *m;
    u8 *pv;

    func_0044DF40(pos, tmp, 1);
    m = func_00435E70(7352, 512);
    if (m != 0) {
        *(u8 *)(m + 48) = 255;
        *(s16 *)(m + 50) = 255;
        *(u8 *)(m + 49) = 1;
        *(u8 *)(m + 32) = 0;
        pv = *(u8 **)(m + 104);
        *(s128_3D6578 *)(m + 16) = *(s128_3D6578 *)pos;
        *(s128_3D6578 *)pv = *(s128_3D6578 *)dir;
        *(f32 *)(m + 44) = 0.1f;
        *(s32 *)(pv + 16) = 0;
        *(s32 *)(pv + 20) = 40;
        func_0040C0F0(tmp2, dir, 1.0f);
        *(f32 *)(pv + 336) = -2.25f;
        *(s32 *)(pv + 44) = -1;
        *(f32 *)(pv + 320) = 2.25f;
        *(s32 *)(pv + 324) = 0;
        *(s32 *)(pv + 328) = 0;
        *(f32 *)(pv + 332) = 1.0f;
        *(s32 *)(pv + 340) = 0;
        *(s32 *)(pv + 344) = 0;
        *(f32 *)(pv + 348) = 1.0f;
        *(s32 *)(pv + 36) = 0;
        *(f32 *)(m + 248) = func_0040CEC8(func_0040C490(dir[0], dir[1]), 1.5707964f);
        *(f32 *)(m + 240) = -func_0040C490(func_0040BF68(dir), dir[2]);
        func_0040C638(m + 192, m + 240);
        func_0040C0F0(pv, pv, 0.5f);
        func_0040C0F0(m + 208, m + 208, 3.0f);
        *(u8 *)(m + 35) = 64;
        *(u16 *)(m + 52) = (*(u16 *)(m + 52) | 0x100) & ~0x200;
        func_00438908(m, 0, 0, 0);
        *(s32 *)(pv + 28) = func_004C4A18(m, 1.0f, 1.0f, 1.0f, 0);
    }
    return m;
}
/* localdecomp:end func_003D6578 */
