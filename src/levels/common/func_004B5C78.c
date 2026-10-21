#include "common.h"

/* localdecomp:start func_004B5C78 */
typedef struct {
    u8 pad0[0x30];
    s32 w30;
    s32 w34;
    u8 pad38[4];
    s32 w3C;
    u8 pad40[8];
    s16 h48;
    u8 pad4A[0xE];
    s32 w58;
    u8 pad5C[2];
    s16 h5E;
    u8 pad60[8];
    s32 w68;
    s32 w6C;
    s32 w70;
    s32 w74;
    s32 w78;
    s16 h7C;
    s16 h7E;
    f32 f80;
    f32 f84;
    f32 f88;
    f32 f8C;
} G_004B5C78;

typedef struct {
    u8 pad0[0x25C0];
    s32 w25C0;
    u8 pad25C4[0x21];
    u8 b25E5;
} A_004B5C78;

typedef struct {
    u8 pad0[0xC];
    s32 wC;
    s32 w10;
} H_004B5C78;

typedef struct {
    u8 pad0[4];
    s16 h4;
    u8 pad6[0x70];
    s16 h76;
    u8 pad78[0x20];
    s16 h98;
    u8 pad9A[4];
    s16 h9E;
} K_004B5C78;

extern u32 D_00142BA0[];
extern s32 D_001EA840[];
extern G_004B5C78 D_001E6E00;
extern s32 D_001E1520;
extern s32 D_001E1460;
extern u8 D_00251480[][64];
extern s32 D_001E14A0;
extern s32 D_001E14E0;
extern u8 D_00244580[][64];
extern s32 D_001E10F0;
extern H_004B5C78 D_001EA9C0;
extern f32 D_001D6718;
extern s32 D_001D671C;
extern f32 D_001DF9D0[1];
extern s32 D_001DF9D8[1];
extern A_004B5C78 D_001A4BE0;
extern u8 D_001DFA64;
extern u8 D_001DFA65;
extern u8 D_001DFA66;
extern f32 D_001DFA68;
extern f32 D_001DFA6C;
extern f32 D_001DFA70;
extern f32 D_001DFA74;
extern s32 D_001D6694;
extern s32 D_001D6720;
extern u8 *D_001DFC98;
extern K_004B5C78 D_001CCFD0;
extern s32 D_001DF9DC;
extern s32 D_001DF9E0;
extern u8 D_00143950[];
extern s32 D_001D545C;

extern void func_00417B68(s32 *);
extern s32 func_004AD7B0(s32);
extern void func_0045BF98(s32);
extern void func_0045CA60(s32);
extern void func_0040BBA8(void *, s32, s32);
extern void func_00418028(void);
extern s32 func_004FC518(s32, s32);
extern void func_0050C8E8(s32);
extern void func_004A8E50(void);
extern void func_00429618(s32, s32);
extern s32 func_00429450(s32, s32);
extern s32 func_004296B0(s32);
extern void func_004294D0(void);
extern void func_004B5C00(s32);
extern void func_00429740(void);
extern void func_0040BD80(s32, s32, s32);
extern void func_0045C240(void);
extern void func_0045CEC0(s32, s32);
extern void func_0045CE98(void);
extern void func_004A57D8(void);
extern s32 func_0012C908(s32);
extern void func_0045CE70(f32);
extern void func_0045B9C8(void);

void func_004B5C78(s32 a0) {
    s32 id;
    s32 i;
    s32 j;
    s32 k;
    f32 *pf;
    s32 *pi;
    s32 v;
    s32 w;
    s32 lo;
    s32 hi;
    s32 r;

    if (a0 >= 0) {
        u32 *bits = &D_00142BA0[(u32)a0 >> 2];
        *bits |= 1 << (a0 & 0x1F);
    }
    func_00417B68(D_001EA840);
    id = func_004AD7B0(a0);
    if (id < 0) {
        return;
    }
    if (D_001E6E00.h5E == 0) {
        func_0045BF98(0);
        func_0045CA60(0);
    }
    func_0040BBA8(&D_001E6E00, 0, 480);
    func_0040BBA8(&D_001E1520, 0, 64);
    func_0040BBA8(&D_001E1460, 0, 64);
    func_0040BBA8(D_00251480[0], 0, 64);
    func_0040BBA8(D_00251480[1], 0, 64);
    func_0040BBA8(&D_001E14A0, 0, 64);
    func_0040BBA8(&D_001E14E0, 0, 64);
    for (j = 0; j < 7; j++) {
        func_0040BBA8(D_00244580[j], 0, 64);
    }
    D_001D6718 = 1.0f;
    D_001D671C = 0;
    D_001E6E00.w30 = id;
    D_001E6E00.w34 = 0;
    D_001E6E00.w3C = 0;
    D_001E10F0 -= 0x90000;
    D_001E6E00.w68 = D_001EA9C0.wC + D_001E10F0;
    D_001E6E00.w6C = D_001E6E00.w68 + 0x60000;
    D_001E6E00.w58 = D_001EA9C0.w10 + D_001E10F0;
    func_00418028();
    pi = D_001DF9D8;
    pf = D_001DF9D0;
    for (k = 0; k < 1; k++) {
        *pf++ = 1.0f;
        *pi++ = 0;
    }
    D_001D6694 = 2;
    D_001E6E00.w70 = D_001DFA64;
    D_001E6E00.w74 = D_001DFA65;
    D_001E6E00.w78 = D_001DFA66;
    D_001E6E00.f80 = D_001DFA68;
    D_001E6E00.f84 = D_001DFA6C;
    D_001E6E00.f88 = D_001DFA70;
    D_001E6E00.f8C = D_001DFA74;
    D_001D6720 = 0;
    if (D_001A4BE0.w25C0 != 0) {
        func_004FC518(101, 2);
        D_001A4BE0.b25E5 = 1;
        func_0050C8E8(0);
    }
    func_004A8E50();
    if (D_001DFC98 != 0) {
        *(u16 *)(D_001DFC98 + 0x34) |= 1;
    }
    D_001DF9DC = 1;
    D_001DF9E0 = 52;
    if (D_001CCFD0.h4 != 0) {
        func_0045CA60(1);
    }
    if (D_00143950[6] != 0) {
        func_00429618(D_001D545C, id);
    }
    r = func_00429450(D_001D545C, id);
    func_004296B0(0);
    if (r != 0) {
        func_004294D0();
    }
    func_004B5C00(1);
    if (D_001CCFD0.h4 != 0) {
        func_0045CA60(1);
    }
    func_00429740();
    if (D_001E6E00.h7E != 0 && D_001E6E00.h7C != 0) {
        lo = D_001E6E00.h7E << 11;
        hi = D_001E6E00.h7C << 11;
        if (lo <= 0x2FFFF) {
            if (hi <= 0x5FFFF) {
                v = D_001EA9C0.wC + D_001E10F0 + 0x90000;
                v -= lo;
                func_0040BD80(v, D_001E6E00.w6C, lo);
                D_001E6E00.w6C = v;
                D_001E6E00.w68 = v - hi;
                func_00429740();
                D_001E10F0 = D_001E6E00.w68 - D_001EA9C0.wC;
                w = D_001E6E00.w58 - D_001EA9C0.w10;
                if (w < D_001E10F0) {
                    D_001E10F0 = w;
                }
            }
        }
    }
    if (D_001CCFD0.h76 != 6 && D_001CCFD0.h76 != 7) {
        D_001CCFD0.h76 = 5;
    }
    if (D_001CCFD0.h9E != 6 && D_001CCFD0.h9E != 7) {
        D_001CCFD0.h9E = 5;
    }
    func_0045C240();
    func_0045CEC0(D_001E6E00.w30, 0);
    func_0045CE98();
    i = 0;
    for (;;) {
        func_004A57D8();
        func_0012C908(0);
        if (i > 300) {
            break;
        }
        i++;
        if (D_001CCFD0.h76 == 0 && D_001CCFD0.h9E == 3 && D_001CCFD0.h98 < 7000) {
            break;
        }
    }
    func_0045CE70(0.82f);
    i = 0;
    D_001E6E00.h48 = -3;
    func_0045B9C8();
    func_004296B0(1);
    while (D_001E6E00.h48 < i) {
        func_0012C908(0);
        i--;
    }
}
/* localdecomp:end func_004B5C78 */
