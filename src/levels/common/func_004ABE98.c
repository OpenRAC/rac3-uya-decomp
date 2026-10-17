#include "common.h"
extern void func_0045C8A8(s32, s32, s32);
extern void func_0045CA60(s32);
typedef struct {
    u8 pad[0x30]; s32 f30; s32 f34; u8 pad38[4]; s32 f3C; u8 pad40[8]; s16 f48; u8 pad4A[2]; s32 f4C;
    u8 pad50[8]; s32 f58; u8 pad5C[0x68 - 0x5C]; s32 f68; s32 f6C; u8 pad70[0x1E0 - 0x70];
} S_225780_4ABE98;
typedef struct { u8 pad[8]; s32 f8; s32 fC; u8 pad10[0x14C - 0x10]; } R_4ABE98;
typedef struct { u8 pad[0x1284]; s32 f1284; u8 pad1288[0x1300 - 0x1288]; R_4ABE98 r[1]; } S_160C40_4ABE98;
typedef struct { u8 pad[4]; s16 f4; u8 pad6[0x76 - 6]; s16 f76; u8 pad78[0x98 - 0x78]; s16 f98; u8 pad9A[4]; s16 f9E; } S_1CCFD0_4ABE98;
typedef struct { u8 pad[6]; u8 f6; u8 pad7[9]; } S_143950_4ABE98;
extern S_225780_4ABE98 D_001E6E00;
extern S_160C40_4ABE98 D_00160C40;
extern S_1CCFD0_4ABE98 D_001CCFD0;
extern S_143950_4ABE98 D_00143950;
extern u32 D_00142BA0[];
extern s32 D_001EAA2C[];
extern u8 D_001A5DC0[];
extern u8 D_001E1520[8];
extern u8 D_001E1460[8];
extern u8 D_00251480[];
extern u8 D_001E14A0[8];
extern u8 D_001E14E0[8];
extern f32 D_001D6718;
extern s32 D_001D671C;
extern s32 D_001D6694;
extern s32 D_001DF9DC;
extern s32 D_001DF9E0;
extern f32 D_001DF9D0[1];
extern s32 D_001DF9D8[1];
extern void func_0040BBA8(void *, s32, s32);
extern s32 func_004ABE68(s32);
extern void func_00402A10(s32);
extern s32 func_004AB778(s32);
extern void func_004ABC38(void);
extern void func_004ACF88(void);
extern void func_0045CEC0(s32, s32);
extern s32 func_004A57D8(void);
extern s32 func_0012C908(s32);
extern s32 func_0045B9C8(void);
s32 func_004ABE98(s32 lvl) {
    s32 slot;
    s32 b;
    s32 i;
    s32 dst;
    s32 n;
    s32 off;
    S_143950_4ABE98 *p;
    if (lvl >= 0) { u32 *w = &D_00142BA0[(u32)lvl >> 2]; *w |= 1 << (lvl & 0x1F); }
    slot = func_004ABE68(lvl);
    if (slot < 0) return 0;
    func_0040BBA8(D_001A5DC0, 0, 0x230);
    func_0040BBA8(&D_001E6E00, 0, 0x1E0);
    func_0040BBA8(D_001E1520, 0, 0x40);
    func_0040BBA8(D_001E1460, 0, 0x40);
    func_0040BBA8(D_00251480, 0, 0x40);
    func_0040BBA8(D_00251480 + 0x40, 0, 0x40);
    func_0040BBA8(D_001E14A0, 0, 0x40);
    func_0040BBA8(D_001E14E0, 0, 0x40);
    b = D_001EAA2C[0];
    D_001E6E00.f30 = slot;
    D_001E6E00.f68 = b - 0x82000;
    D_001E6E00.f6C = b - 0x102000;
    D_001D6718 = 1.0f;
    D_001D671C = 0;
    D_001E6E00.f34 = 0;
    D_001E6E00.f3C = 0;
    D_001E6E00.f58 = b - 0x90000;
    { s32 j; for (j = 0; j < 1; j++) { D_001DF9D0[j] = 1.0f; D_001DF9D8[j] = 0; } }
    D_001D6694 = 2;
    D_001DF9DC = 1;
    D_001DF9E0 = 0x34;
    p = &D_00143950;
    if (p->f6 != 0) {
        D_001E6E00.f4C = 0;
        dst = D_001E6E00.f58 + 0x8E000;
        n = D_00160C40.r[D_001E6E00.f30].fC;
        off = D_00160C40.r[D_001E6E00.f30].f8;
        if (n > 0) {
            func_0045C8A8(dst, off + D_00160C40.f1284, n);
            func_0045CA60(1);
            D_001E6E00.f4C = dst;
        }
    }
    if (D_001CCFD0.f4 != 0) {
        func_00402A10(6);
        func_0045CA60(1);
        func_004AB778(0);
    } else {
        func_004AB778(0);
        func_00402A10(6);
    }
    if (D_001CCFD0.f4 != 0) func_0045CA60(1);
    func_004ABC38();
    func_004ACF88();
    func_0045CEC0(D_001E6E00.f30 + 4000, 0);
    while (D_001CCFD0.f76 != 0 || D_001CCFD0.f9E != 3 || D_001CCFD0.f98 >= 7000) {
        func_004A57D8();
        func_0012C908(0);
    }
    D_001E6E00.f48 = -3;
    func_0045B9C8();
    func_004AB778(1);
    for (i = 0; D_001E6E00.f48 < i; i--) func_0012C908(0);
    return 1;
}
