#include "common.h"

extern void func_00445660(s32 a0);
extern void func_004506F0(void *a0, s32 a1, s32 a2);
extern void func_004660E8(s32 a0);
extern s32 D_001D545C;
extern s32 D_001D67AC;
extern s32 D_001D67B4;
extern s32 D_001D67C0;
extern s32 D_001DD708;

void func_00361560(u8 *a0) {
    u8 *s0;
    u8 *m;
    s32 n;

    s0 = *(u8 **)(a0 + 0x68);
    if (s0 == 0) {
        return;
    }
    if (D_001D545C == 4 && (m = *(u8 **)(s0 + 0x48)) != 0
        && (*(s16 *)(m + 0xAA) == 0x185E || *(s16 *)(m + 0xAA) == 0x11C1)) {
        n = D_001D67AC + 1;
        D_001D67AC = n;
        if (n >= 0x19) {
            func_004660E8(6);
        }
    } else if (D_001D545C == 0xC && *(u8 **)(s0 + 0x48) != 0 && s0[0x47] == 9) {
        n = D_001D67B4 + 1;
        D_001D67B4 = n;
        if (n >= 0x14) {
            func_004660E8(0xF);
        }
    } else if (D_001D545C == 0x12 && (m = *(u8 **)(s0 + 0x48)) != 0
        && (*(s16 *)(m + 0xAA) == 0x185E || *(s16 *)(m + 0xAA) == 0x11C1)) {
        n = D_001D67C0 + 1;
        D_001D67C0 = n;
        if (n >= 0x14) {
            func_004660E8(0x15);
        }
    }
    if (*(s32 *)(s0 + 0x2FC) != 0) {
        func_00445660(*(s32 *)(s0 + 0x2FC));
        *(s32 *)(s0 + 0x2FC) = 0;
        *(s32 *)(s0 + 0x240) = 0;
    }
    if (*(s32 *)(s0 + 0x4F8) != 0 && s0[0x47] == 0x6F) {
        n = D_001DD708 + 1;
        D_001DD708 = n;
        if (n >= 0xA) {
            func_004660E8(0xD);
        }
    }
    func_004506F0(a0, 0, 3);
}
