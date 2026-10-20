#include "common.h"
typedef struct {
    u8 pad0[136];
    f32 f136;
    u8 pad8C[140];
    f32 f280;
    u8 pad11C[192];
    s16 f476;
    s16 f478;
    u8 pad1E0[344];
    f32 f824;
    f32 f828;
    u8 pad340[16];
    f32 f848;
    f32 f852;
    u8 pad358[8];
    s32 f864;
    u8 pad364[4];
    s16 f872;
    u8 pad36A[2];
    s16 f876;
    u8 pad36E[256];
    u8 f1134;
    u8 pad46F[4097];
    s16 f5232;
    u8 pad1472[2];
    u8 f5236;
    u8 f5237;
    u8 f5238;
    u8 f5239;
    u8 f5240;
    u8 f5241;
    u8 pad147A[2];
    u8 f5244;
    u8 f5245;
    u8 f5246;
    u8 f5247;
    u8 pad1480[4416];
    s32 f9664;
    s32 f9668;
    u8 pad25C8[4];
    s32 f9676;
    u8 pad25D0[20];
    u8 f9700;
    u8 pad25E5[5];
    u8 f9706;
    u8 pad25EB[3];
    u8 f9710;
    u8 pad25EF[601];
    f32 f10312;
    u8 pad284C[4];
    s32 f10320;
} P_004E3EF0;
extern P_004E3EF0 D_001A4BE0;
extern u8 D_00142CAD[];
extern s32 D_00142668[];
extern void func_0040BBD0(void *, s32);
extern void func_004DC1C0(s32);
extern void func_004FC518(s32, s32);
extern void func_004E3EC0(void);


void func_004E3EF0(void) {
    s16 state;
    u8 b;
    s32 s4;
    f32 d;

    state = D_001A4BE0.f5232;
    b = D_001A4BE0.f5247;
    func_0040BBD0(&D_001A4BE0.f5232, 16);
    D_001A4BE0.f5247 = b;
    D_001A4BE0.f5232 = state;
    D_001A4BE0.f9706 = 0;
    D_001A4BE0.f872 = 0;
    if (D_001A4BE0.f9710 != 0) {
        return;
    }
    s4 = 0;
    if (D_001A4BE0.f864 != 0 || (D_001A4BE0.f9668 == 128 && D_001A4BE0.f828 < 0.4f)) {
        s4 = 1;
    }
    if (state == -1) {
        return;
    }
    if (state == 2 || state == 17 || state == 18) {
        if (D_001A4BE0.f478 == 0) {
            if (D_001A4BE0.f876 == 0 || D_001A4BE0.f828 < 2.5f) {
                D_001A4BE0.f5241 = 1;
                if (D_001A4BE0.f9700 == 0 && D_00142CAD[0] != 0) {
                    D_001A4BE0.f872 = 1;
                }
            }
        }
    }
    if (state == 17 && D_001A4BE0.f476 == 0 && D_001A4BE0.f876 == 0 && D_001A4BE0.f9676 != 7) {
        func_004DC1C0(D_00142668[0] / 8);
        D_001A4BE0.f476 = 90;
        func_004FC518(177, 1);
    }
    if (state == 14) {
        D_001A4BE0.f5238 = 1;
        D_001A4BE0.f10312 = 0.2f;
        D_001A4BE0.f848 = D_001A4BE0.f824 + 0.2f;
    }
    if (state == 0) {
        d = D_001A4BE0.f848 - D_001A4BE0.f824;
        D_001A4BE0.f10312 = d;
        if (d < 0.85f && 0.25f < d) {
            D_001A4BE0.f9706 = 1;
        }
        D_001A4BE0.f5238 = 1;
    }
    if (state == 3) D_001A4BE0.f5240 = 1;
    if (state == 11) D_001A4BE0.f5245 = 1;
    if (state == 4) D_001A4BE0.f5237 = 1;
    if (state == 7) D_001A4BE0.f5236 = 1;
    if (state == 13) D_001A4BE0.f5246 = 1;
    if (state == 1) D_001A4BE0.f5239 = 1;
    if (state == 8 || state == 18) D_001A4BE0.f5244 = 1;
    if (state == 12) D_001A4BE0.f5244 = 1;

    if (D_001A4BE0.f5237 && s4 && D_001A4BE0.f9676 != 16 && D_001A4BE0.f9676 != 20 && D_001A4BE0.f9676 != 7) {
        func_004FC518(48, 1);
        return;
    }
    if (D_001A4BE0.f5239 && s4 && D_001A4BE0.f9700 == 1 && D_001A4BE0.f9668 != 127) {
        func_004FC518(127, 1);
        return;
    }
    if (D_001A4BE0.f5239 && s4 && (D_001A4BE0.f9668 != 56 || D_001A4BE0.f1134 != 0)) {
        func_004E3EC0();
        if (D_001A4BE0.f10320 != 0) {
            func_004FC518(56, 1);
        } else if (*(s32 *)(*(s32 *)(D_001A4BE0.f9664 + 36) + 424) != 0) {
            func_004FC518(126, 1);
        } else {
            func_004FC518(57, 1);
        }
        return;
    }
    if (D_001A4BE0.f9700 == 1) {
        if (D_001A4BE0.f5246 && D_001A4BE0.f9668 != 80) {
            if (__builtin_fabsf(D_001A4BE0.f848 - (D_001A4BE0.f136 + 0.15f)) < 0.5f && 0.0f < D_001A4BE0.f848 - D_001A4BE0.f136) {
                if (D_001A4BE0.f280 < 0.0f || D_001A4BE0.f9668 == 128) {
                    func_004FC518(80, 1);
                    return;
                }
            }
        }
    } else {
        if (D_001A4BE0.f5246 && D_001A4BE0.f9668 != 129) {
            if (__builtin_fabsf(D_001A4BE0.f848 - (D_001A4BE0.f136 + 0.25f)) < 1.0f && 0.0f < D_001A4BE0.f848 - D_001A4BE0.f136) {
                if (D_001A4BE0.f280 < 0.0f || D_001A4BE0.f9668 == 128) {
                    func_004E3EC0();
                    func_004FC518(129, 1);
                    return;
                }
            }
        }
    }
    if (D_001A4BE0.f5240 && D_001A4BE0.f9668 != 106 && D_001A4BE0.f9668 != 125) {
        if (__builtin_fabsf(D_001A4BE0.f852 - (D_001A4BE0.f136 + 0.25f)) < 1.0f && 0.0f < D_001A4BE0.f852 - D_001A4BE0.f136) {
            if (D_001A4BE0.f9668 != 107 || D_001A4BE0.f1134 != 0) {
                if (D_001A4BE0.f280 < 0.0f || D_001A4BE0.f9668 == 128) {
                    func_004E3EC0();
                    if (D_001A4BE0.f10320 == 0) {
                        func_004FC518(125, 1);
                    } else {
                        func_004FC518(106, 1);
                    }
                    return;
                }
            }
        }
    }
    if (D_001A4BE0.f5245 && D_001A4BE0.f9668 != 125 && D_001A4BE0.f9668 != 121) {
        if (__builtin_fabsf(D_001A4BE0.f852 - (D_001A4BE0.f136 + 0.25f)) < 1.0f && 0.0f < D_001A4BE0.f852 - D_001A4BE0.f136) {
            if (D_001A4BE0.f280 < 0.0f || D_001A4BE0.f9668 == 128) {
                func_004E3EC0();
                func_004FC518(125, 1);
            }
        }
    }
}
