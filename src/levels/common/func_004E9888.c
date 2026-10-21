#include "common.h"

/* localdecomp:start func_004E9888 */
typedef int s128 __attribute__((mode(TI)));

typedef struct M004E9888 {
    u8 pad0[16];
    s128 pos;
    u8 pad20[52 - 32];
    u16 h52;
    u8 pad36[64 - 54];
    u8 b64;
    u8 b65;
    u8 b66;
    u8 b67;
    u8 pad44[88 - 68];
    s32 w88;
    s32 w92;
    u8 pad60[156 - 96];
    s32 w156;
} M004E9888;

typedef struct {
    u8 pad0[128];
    s128 q128;
    u8 pad90[3060 - 144];
    M004E9888 *m3060;
    M004E9888 *m3064;
    M004E9888 *m3068;
    u8 padC00[3076 - 3072];
    f32 f3076;
    u8 padC08[6672 - 3080];
    s32 w6672;
    u8 pad1A14[6688 - 6676];
    M004E9888 *m6688;
    M004E9888 *m6692;
    u8 pad1A28[6736 - 6696];
    M004E9888 *m6736;
    u8 pad1A54[6744 - 6740];
    M004E9888 *m6744;
    u8 pad1A5C[9664 - 6748];
    M004E9888 *m9664;
    s32 w9668;
    u8 pad25C8[9700 - 9672];
    u8 b9700;
    u8 pad25E5[10320 - 9701];
    s32 w10320;
    s32 w10324;
    s16 h10328;
} P004E9888;

extern P004E9888 D_001A4BE0;
extern s32 D_001D6694;
extern u8 D_0041AAC8[];
extern u8 D_0041AB20[];
extern u8 D_0041B4E8[];
extern u8 D_00252900[];
extern u8 D_00252F00[8];
extern void func_00436220(M004E9888 *);
extern void func_00436C90(M004E9888 *, s32 *);
extern void func_004DC7D8(void);
extern void func_0041A170(s32, s32, void *, void *, void *, s32, s32);
extern void func_0041A120(s32);
extern void func_004DD850(void);
extern void func_0050BF28(void);
extern s32 func_004DBFE8(M004E9888 *, s32, s32, void *);
extern void func_004FC518(s32, s32);

void func_004E9888(void) {
    M004E9888 *m;

    if (D_001A4BE0.b9700 == 1) {
        D_001A4BE0.w10324 = D_001A4BE0.w10320;
        D_001A4BE0.w10320 = D_001A4BE0.h10328;
        if (D_001A4BE0.m6688) {
            func_00436220(D_001A4BE0.m6688);
            D_001A4BE0.m6688 = 0;
        }
        if (D_001A4BE0.m6692) {
            func_00436220(D_001A4BE0.m6692);
            D_001A4BE0.m6692 = 0;
        }
        if (D_001A4BE0.m6736) {
            func_00436220(D_001A4BE0.m6736);
            D_001A4BE0.m6736 = 0;
        }
        if (D_001A4BE0.m6744) {
            func_00436220(D_001A4BE0.m6744);
            D_001A4BE0.m6744 = 0;
        }
        if (D_001A4BE0.w6672) {
            func_00436C90(D_001A4BE0.m9664, &D_001A4BE0.w6672);
        }
    }
    func_004DC7D8();
    D_001A4BE0.b9700 = 0;
    func_0041A170(35, 0, D_0041AAC8, D_0041AB20, D_0041B4E8, 0, 0);
    func_0041A120(3);
    if (D_001A4BE0.m3060) {
        D_001A4BE0.m3060->h52 &= 0xFFF9;
    }
    D_001A4BE0.m3060 = 0;
    if (D_001A4BE0.m3068) {
        func_00436220(D_001A4BE0.m3068);
        D_001A4BE0.m3068 = 0;
    }
    func_004DD850();
    D_001A4BE0.m9664 = D_001A4BE0.m3064;
    D_001A4BE0.m3064->pos = D_001A4BE0.q128;
    D_001A4BE0.m9664->w156 = 0;
    D_001A4BE0.f3076 = 1.0f;
    func_0050BF28();
    m = D_001A4BE0.m9664;
    if (m->b66 != 255) {
        D_001A4BE0.m9664->w88 = func_004DBFE8(m, m->b66, m->b64, D_00252900);
    }
    m = D_001A4BE0.m9664;
    D_001A4BE0.m9664->w92 = func_004DBFE8(m, m->b67, m->b65, D_00252F00);
    if (D_001A4BE0.w9668 != 101 || (D_001D6694 != 2 && D_001D6694 != 6)) {
        func_004FC518(0, 1);
    }
}
/* localdecomp:end func_004E9888 */
