#include "common.h"

/* localdecomp:start func_004EA708 */
typedef int s128 __attribute__((mode(TI)));

typedef struct {
    /* 0x0000 */ u8 pad0[64];
    /* 0x0040 */ u8 v64[64];
    /* 0x0080 */ s128 v128;
    /* 0x0090 */ u8 v144[8];
    /* 0x0098 */ f32 f152;
    /* 0x009C */ u8 pad9c[656 - 156];
    /* 0x0290 */ s32 w656;
    /* 0x0294 */ u8 pad294[5172 - 660];
    /* 0x1434 */ s16 h5172;
    /* 0x1436 */ u8 pad1436[8256 - 5174];
    /* 0x2040 */ s128 hist[32];
    /* 0x2240 */ u8 pad2240[8800 - 8768];
    /* 0x2260 */ f32 f8800;
    /* 0x2264 */ f32 f8804;
    /* 0x2268 */ u8 pad2268[9668 - 8808];
    /* 0x25C4 */ s32 w9668;
    /* 0x25C8 */ u8 pad25c8[9716 - 9672];
    /* 0x25F4 */ u8 b9716;
    /* 0x25F5 */ u8 pad25f5[9836 - 9717];
    /* 0x266C */ f32 fhist[32];
    /* 0x26EC */ s32 w9964;
    /* 0x26F0 */ s32 w9968;
    /* 0x26F4 */ s32 w9972;
    /* 0x26F8 */ s32 w9976;
    /* 0x26FC */ u8 pad26fc[10296 - 9980];
    /* 0x2838 */ f32 f10296;
    /* 0x283C */ f32 f10300;
    /* 0x2840 */ f32 f10304;
} func_004EA708_P;

extern func_004EA708_P D_001A4BE0;
extern u8 D_001A6EC0[];
extern u8 D_001A6014[];
extern u8 *D_001D52FC;
extern s32 func_0050FF18(void);
extern void func_0040BAC0(void *a0);
extern u8 func_0050CE68(void);
extern f32 func_004EA9A8(void);
extern f32 func_0040BF68(void *a0);
extern f32 func_0040C490(f32 a, f32 b);
extern void **func_00438488(s32 a0, s32 a1, s32 a2);
extern void func_004F2090(void);
extern void func_0040C658(void *a0, void *a1);
extern void func_0040C5D0(void *a0);
extern void func_0040C8E0(void *a0, void *a1);
extern void func_004EA298(s32 a0);
extern void func_004FA7B0(void);
extern void func_004FAA68(void);

void func_004EA708(void) {
    void **prof;
    s32 pad;
    u8 *pl;
    func_004EA708_P *q;
    s32 t;

    *(s128 *)D_001A6EC0 = *(s128 *)(D_001A6EC0 - 8800);
    if ((*(u32 *)(D_001D52FC + 416) & 3) && func_0050FF18() == 0) {
        q = (func_004EA708_P *)(D_001A6EC0 - 8928);
        if (q->h5172 <= 0) {
            q->h5172 = 1;
        }
    } else {
        func_0040BAC0(D_001A6014);
    }
    if (D_001A4BE0.w9668 == 16) {
        D_001A4BE0.h5172 = 0;
    }
    D_001A4BE0.b9716 = func_0050CE68();
    D_001A4BE0.w656 = 0;
    D_001A4BE0.f8800 = *(f32 *)(D_001D52FC + 264);
    D_001A4BE0.f8804 = -*(f32 *)(D_001D52FC + 268);
    D_001A4BE0.f10300 = func_004EA9A8();
    if (func_0040BF68(&D_001A4BE0.f8800) < 0.25f) {
        pl = D_001D52FC;
        t = ((*(s32 *)(pl + 432) >> 13) & 1) - ((*(s32 *)(pl + 432) >> 15) & 1);
        D_001A4BE0.f8800 = (f32)t;
        t = (*(s32 *)(pl + 432) >> 14) & 1;
        D_001A4BE0.f8804 = (f32)((*(s32 *)(pl + 432) & 0x1000) ? 1 - t : -t);
    }
    D_001A4BE0.f10296 = func_004EA9A8();
    D_001A4BE0.f10304 = func_0040C490(D_001A4BE0.f8800, D_001A4BE0.f8804);
    prof = func_00438488(7791, 0, 12);
    if (prof != 0) {
        ((void (*)(void))prof[1])();
    }
    func_004F2090();
    D_001A4BE0.fhist[D_001A4BE0.w9964] = D_001A4BE0.f152;
    D_001A4BE0.w9964 = (D_001A4BE0.w9964 + 1) % 32;
    if (++D_001A4BE0.w9968 > 32) {
        D_001A4BE0.w9968 = 32;
    }
    D_001A4BE0.hist[D_001A4BE0.w9972] = D_001A4BE0.v128;
    D_001A4BE0.w9972 = (D_001A4BE0.w9972 + 1) % 32;
    if (++D_001A4BE0.w9976 > 32) {
        D_001A4BE0.w9976 = 32;
    }
    func_0040C658(&D_001A4BE0, D_001A4BE0.v144);
    func_0040C5D0(D_001A4BE0.v64);
    func_0040C8E0(D_001A4BE0.v64, &D_001A4BE0);
    func_004EA298(0);
    func_004FA7B0();
    func_004FAA68();
    if (prof != 0) {
        ((void (*)(void))prof[2])();
    }
}
/* localdecomp:end func_004EA708 */
