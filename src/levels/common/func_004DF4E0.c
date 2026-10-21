#include "common.h"

/* localdecomp:start func_004DF4E0 */
typedef struct {
    u8 pad0[0x21C];
    s16 h21C;
    u8 pad21E[0x180E];
    f32 f1A2C;
    f32 v1A30[4];
    f32 v1A40[4];
    u8 pad1A50[0x4];
    s32 i1A54;
    u8 pad1A58[0x868];
    f32 v22C0[4];
    f32 f22D0[3];
    u8 pad22DC[0x14];
    f32 v22F0[8][4];
    s32 i2370[8];
    f32 f2390[8];
    f32 f23B0[8];
    s16 h23D0;
    u8 pad23D2[0x212];
    u8 b25E4;
    u8 pad25E5[0x29F];
    s16 h2884;
    u8 pad2886[0x2];
    s16 h2888;
    u8 pad288A[0x1E];
    s16 h28A8;
    u8 pad28AA[0x2];
    s32 i28AC;
} B_4DF4E0;

extern B_4DF4E0 D_001A4BE0;
extern f32 D_001A6EA0[];
extern s32 D_001D6694;
extern volatile u8 D_001D5470;

extern void func_0044E620(f32 *, s32, f32, f32);
extern f32 func_0040C3E0(f32);
extern void func_004035F8(s32, s32, s32, s32);
extern void func_004C1FE8(s32, unsigned long);
extern s32 func_004E5470(s32);
extern s32 func_0040D020(s32, s32, f32);
extern void func_004C3500(f32 *, f32 *, s32, s32, f32);
extern void func_004450C0(f32 *, f32, f32);

void func_004DF4E0(void) {
    s32 i;
    f32 f;

    if (D_001D6694 == 2 || D_001D6694 == 6) {
        for (i = 0; i < D_001A4BE0.h23D0; i++) {
            func_0044E620(D_001A4BE0.v22F0[i], D_001A4BE0.i2370[i], D_001A4BE0.f2390[i], D_001A4BE0.f23B0[i]);
        }
        return;
    }
    if (D_001A4BE0.h21C != 0) {
        func_004035F8(170, 0, 0, (func_0040C3E0((f32)D_001A4BE0.h21C * 3.1415927f / 18.0f) * 0.5f + 0.5f) * 80.0f);
        func_004C1FE8(71, 0x5360B);
    }
    if (D_001A4BE0.b25E4 == 0) {
        if ((func_004E5470(3) == 3 || func_004E5470(3) == 2) && D_001A4BE0.h2884 == 0) {
            if (D_001A4BE0.h2888 != 0) {
                f = 1.0f;
                if (f < D_001A4BE0.f22D0[0]) {
                    f = D_001A4BE0.f22D0[0];
                }
                if (f < D_001A4BE0.f22D0[1]) {
                    f = D_001A4BE0.f22D0[1];
                }
                if (f < D_001A4BE0.f22D0[2]) {
                    f = D_001A4BE0.f22D0[2];
                }
                func_0040D020(0xC0000028, 40, f);
            }
            func_0044E620(D_001A6EA0, 0xC0000028, 0.057f, 0.08f);
        }
        for (i = 0; i < D_001A4BE0.h23D0; i++) {
            func_0044E620(D_001A4BE0.v22F0[i], D_001A4BE0.i2370[i], D_001A4BE0.f2390[i], D_001A4BE0.f23B0[i]);
        }
    } else if (D_001A4BE0.b25E4 == 2) {
        func_0044E620(D_001A4BE0.v22C0, 0x300000C0, 0.25f, 0.08f);
    } else if (D_001A4BE0.b25E4 == 1) {
        if (D_001A4BE0.i1A54 != 0) {
            func_004C3500(D_001A4BE0.v1A30, D_001A4BE0.v1A40, 0, 1, 0.5f);
        }
        f = 0.07f;
        if (D_001A4BE0.h28A8 != 0) {
            f = 0.1015000045f;
        }
        if (D_001D5470 != 0) {
            f *= 1.7f;
        }
        func_004450C0(&D_001A4BE0.f1A2C, f, 0.003f);
        func_0044E620(D_001A4BE0.v22C0, D_001A4BE0.i28AC, D_001A4BE0.f1A2C, 0.08f);
    }
}
/* localdecomp:end func_004DF4E0 */
