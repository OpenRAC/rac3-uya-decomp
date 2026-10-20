#include "common.h"

typedef int s128_4F1FC0 __attribute__((mode(TI)));
typedef int s64_4F1FC0 __attribute__((mode(DI)));

typedef struct {
    u8 pad0[128];
    s128_4F1FC0 q80;
    s128_4F1FC0 q90;
    u8 padA0[2908];
    u8 *unkBFC;
    u8 padC00[6592];
    u8 *unk25C0;
} S_001A4BE0;

extern S_001A4BE0 D_001A4BE0[];
extern u8 D_001FDC50[];
extern s32 D_001FD200[];
extern u8 *func_00435E70(s32, s32);
extern void func_00439610(u8 *);
extern void func_004E9628(s32, s32, u8 *);

void func_004F1FC0(void) {
    s32 type = 5947;
    u8 *m;

    if (D_001FDC50[6734] != 255 && D_001FD200[D_001FDC50[6734]] != 0) {
        type = 6734;
    }
    m = func_00435E70(type, 128);
    D_001A4BE0[0].unkBFC = m;
    if (m != 0) {
        *(s128_4F1FC0 *)(m + 16) = D_001A4BE0[0].q80;
        *(s128_4F1FC0 *)(D_001A4BE0[0].unkBFC + 240) = D_001A4BE0[0].q90;
        *(s16 *)(D_001A4BE0[0].unkBFC + 50) = 64;
        D_001A4BE0[0].unkBFC[49] = 1;
        *(s32 *)(D_001A4BE0[0].unkBFC + 120) = 0;
        *(s64_4F1FC0 *)(D_001A4BE0[0].unkBFC + 56) = *(s64_4F1FC0 *)(D_001A4BE0[0].unk25C0 + 56);
        func_00439610(D_001A4BE0[0].unkBFC);
        func_004E9628(3, 81, D_001A4BE0[0].unkBFC);
    }
}
