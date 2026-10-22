#include "common.h"

typedef int u128_39E538 __attribute__((mode(TI)));

extern s32 func_00335370(u8 *m);
extern f32 func_003E4710(void *a, void *b);
extern void func_00419630(void *m, s32 a, s32 b, s32 c);
extern void func_00419970(void *m, s32 a, s32 b);
extern u8 D_001A4C60[];
extern u8 *D_001DEA1C;
extern u8 D_001E1380[];

s32 func_0039E538(u8 *m, s32 flag) {
    u8 *v;
    u8 *t;
    u8 *tv;

    if (func_003E4710(m + 0x10, D_001A4C60) < 3.0f) {
        return 0;
    }
    if (func_003E4710(m + 0x10, D_001E1380) < 3.0f) {
        return 0;
    }
    v = *(u8 **)(m + 0x68);
    if (v[0x1A] == 0xFF || v[0x1B] < v[0x1A]) {
        v[0x18] = flag & 1;
        if (m[0x20] == 1 && m[0x95] == m[0x20]) {
            if (func_00335370(D_001DEA1C + (*(s32 *)(v + 0) << 8)) != 0) {
                if (*(s32 *)(v + 4) == -1 || func_00335370(D_001DEA1C + (*(s32 *)(v + 4) << 8)) != 0) {
                    t = D_001DEA1C + ((v[0x18] ? *(s32 *)(v + 4) : *(s32 *)(v + 0)) << 8);
                    tv = *(u8 **)(t + 0x68);
                    *(u128_39E538 *)(t + 0x10) = *(u128_39E538 *)(m + 0x10);
                    *(s32 *)(tv + 0xDC) = 0;
                    if (*(s32 *)(v + 0x1C) >= 0) {
                        *(u8 **)(tv + 0x120) = D_001DEA1C + (*(s32 *)(v + 0x1C) << 8);
                        *(u128_39E538 *)(tv + 0x100) = *(u128_39E538 *)(v + 0x20);
                    }
                    *(s32 *)(v + 8) = 0;
                    *(s32 *)(v + 0xC) = 0;
                    if (m[0x43] != 1) {
                        func_00419630(m, 1, 0, 0);
                    }
                    func_00419970(m, 1, 2);
                    if (v[0x1A] != 0xFF) {
                        v[0x1B]++;
                    }
                    return 1;
                }
                return 0;
            }
            return 0;
        }
        return 0;
    }
    return 0;
}
