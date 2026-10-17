#include "common.h"

extern s32 D_001A71A4[];
extern u8 *D_001D52FC;
extern s32 func_004573E8(u8 *a0);
extern void func_004FC518(s32 a0, s32 a1);
extern s32 func_0040BA90(u8 *a0);

s32 func_003292A8(u8 *a0, u8 *a1) {
    if (func_004573E8(a0) == 5) {
        return 0;
    }
    if (D_001A71A4[0] != 116) {
        func_004FC518(116, 1);
    }
    func_0040BA90(a1 + 72);
    func_0040BA90(a1 + 76);
    if (func_0040BA90(a1 + 68) != 0 && (*(s32 *)(D_001D52FC + 452) & 0x40)) {
        return 1;
    }
    return 0;
}
