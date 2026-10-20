#include "common.h"

#define B(p, o) (*(u8 *)((u8 *)(p) + (o)))
#define H(p, o) (*(s16 *)((u8 *)(p) + (o)))
#define W(p, o) (*(s32 *)((u8 *)(p) + (o)))
#define F(p, o) (*(f32 *)((u8 *)(p) + (o)))
#define L(p, o) (*(unsigned long *)((u8 *)(p) + (o)))

extern s32 func_003A4E70(void *);
extern f32 func_0040C018(void *, void *);
extern void func_00444188(void *);
extern s32 func_0044FCD0(void *, void *, s32, s32, s32);
extern void func_004A7200(s32, s32, void *);
extern void func_003A5430(void *);
extern s32 func_0044F5E8(void *, void *, s32);
extern void func_003A5210(void *);
extern void func_004538E0(void *, s32);
extern void func_004539A8(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, s32, s32);
extern u8 D_001E2AC0[];
extern s32 D_001D545C;
extern s32 D_001DFBC0;

s32 func_003A4B78(u8 *m) {
    u8 *v = *(u8 **)(m + 104);

    if (B(m, 32) == 0) {
        if (func_003A4E70(m) != 0) {
            return 1;
        }
    }
    if (B(m, 49) != 0) {
        if (func_0040C018(D_001E2AC0, m + 16) < 576.0f) {
            func_00444188(m);
            B(m, 111) = 22;
        }
    }
    if (B(v, 62) != 2) {
        if (func_0044FCD0(m, v + 352, 0, 0, 0) != 0) {
            func_004A7200(3, 0, m);
            func_003A5430(m);
        }
        func_0044F5E8(m, v + 48, 0);
        if (B(v, 94) == 0) {
            goto rest;
        }
        func_004A7200(3, 0, m);
    }
    func_003A5210(m);
    return 1;
rest:
    if ((L(m, 48) & 0x104100000000L) != 0x4100000000L || W(m, 152) != 0) {
        if (0.0f < F(v, 48)) {
            if (B(v, 95) != 0) {
                func_004538E0(m, 5);
            } else if (D_001D545C != 9 || (u8)(B(m, 149) - 3) < 2) {
                func_004538E0(m, 3);
            }
        }
    }
    if ((H(m, 178) + 8) % 8 != D_001DFBC0 % 8) {
        return 0;
    }
    if (B(v, 95) != 0) {
        if (B(m, 149) == 0) {
            func_004539A8(m, W(v, 720), 0, 0, 0, 0, 3, 0, F(v, 724), 10.0f, 1.0f, 0, 0);
        } else {
            func_004539A8(m, W(v, 728), 0, 0, 0, 0, 3, 0, F(v, 732), 10.0f, 1.0f, 0, 0);
        }
    } else {
        if (B(m, 149) == 0) {
            func_004539A8(m, W(v, 720), 0, 0, 0, 0, 1, W(v, 960) != 0, F(v, 724), 10.0f, 1.0f, 0, 0);
        } else {
            func_004539A8(m, W(v, 728), 0, 0, 0, 0, 1, W(v, 960) != 0, F(v, 732), 10.0f, 1.0f, 0, 0);
        }
    }
    return 0;
}
