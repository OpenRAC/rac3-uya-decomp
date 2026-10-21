#include "common.h"

/* localdecomp:start func_00382830 */
typedef int s128 __attribute__((mode(TI)));

typedef struct {
    u8 pad0;
    u8 unk1;
    u8 pad2[238];
} S_002C5640;

typedef struct {
    u8 pad0[5808];
    s32 unk16B0;
    u8 pad16B4[3852];
    u8 *unk25C0;
} S_001A4BE0;

extern S_001A4BE0 D_001A4BE0[];
extern u8 D_00142647[];
extern S_002C5640 D_002C5640[];

extern u8 *func_00435E70(s32, s32);
extern void func_00442E08(u8 *, s32);
extern f32 func_0040BF38(u8 *);
extern void func_004C7010(u8 *, s128 *, f32, f32, f32);
extern s32 func_004C4A18(u8 *, s32, f32, f32, f32);
extern void func_00439610(u8 *);

u8 *func_00382830(s32 arg0, s128 *arg1, s128 *arg2, s128 *arg3, s32 arg4, s32 arg5, f32 arg6) {
    u8 *mob;
    u8 *pv;

    mob = func_00435E70(6258, 128);
    if (mob != 0) {
        mob[48] = 255;
        *(s16 *)(mob + 50) = 255;
        mob[49] = 1;
        mob[32] = 0;
        pv = *(u8 **)(mob + 104);
        *(long *)(mob + 56) = *(long *)(D_001A4BE0[0].unk25C0 + 56);
        *(s128 *)(mob + 16) = *arg2;
        *(s128 *)(mob + 240) = *arg3;
        func_00442E08(mob, arg4);
        *(s32 *)(pv + 60) = arg4;
        *(s16 *)(mob + 170) = 6258;
        *(f32 *)(mob + 44) = *(f32 *)(*(u8 **)(mob + 36) + 36) * 0.7f;
        *(s128 *)pv = *arg1;
        *(s32 *)(pv + 16) = arg0;
        *(f32 *)(pv + 20) = arg6;
        *(f32 *)(pv + 32) = 0.15f;
        *(s32 *)(pv + 52) = arg5;
        if ((D_00142647[0])[D_002C5640].unk1 >= 2) {
            *(s32 *)(pv + 44) = 0x110000;
        } else {
            *(s32 *)(pv + 44) = 0x10000;
        }
        if (D_001A4BE0[0].unk16B0 != 0) {
            func_004C7010(pv, arg2, func_0040BF38(pv), 30.0f, 0.34906584f);
        }
        *(s32 *)(pv + 56) = func_004C4A18(mob, 0, 1.0f, 1.0f, 1.0f);
        *(s32 *)(pv + 36) = 0;
        func_00439610(mob);
    }
    *(s32 *)(mob + 152) = 0;
    return mob;
}
/* localdecomp:end func_00382830 */
