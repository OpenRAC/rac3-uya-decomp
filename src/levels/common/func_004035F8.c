#include "common.h"

extern void func_004C1FE8(s32, unsigned long);
extern void func_004035F8(s32, s32, s32, s32);
extern s32 D_001A1ED0[];

extern u32 *D_001E10E8_003866E8;
extern u8 D_00141850[];
void func_004035F8(s32 a0, s32 a1, s32 a2, s32 a3) {
    func_004C1FE8(0x4E, ((D_001A1ED0[2] >> 13) | 0x31000000) | (0x8000UL << 17));
    func_004C1FE8(1, (long)a0 | ((long)a1 << 8) | ((long)a2 << 16) | ((long)a3 << 24));
    D_001E10E8_003866E8[0] = 0x30000014;
    D_001E10E8_003866E8[1] = (u32)D_00141850;
    D_001E10E8_003866E8[2] = 0;
    D_001E10E8_003866E8[3] = 0x50000014;
    D_001E10E8_003866E8 += 4;
    func_004C1FE8(0x4E, 0x31000000 | (D_001A1ED0[2] >> 13));
}
