#include "common.h"

extern void func_004C1FE8(s32, unsigned long);
extern s32 D_001A1ED0[];
extern void func_00403708(s32, s32, s32, s32, unsigned long);

extern void func_004C1FE8(s32, unsigned long);
extern void func_00403708(s32, s32, s32, s32, unsigned long);
extern s32 D_001A1ED0[];
extern s16 D_001CFEC0[];
typedef struct { s32 f0; u32 f4; unsigned long f8; } S;
void func_00403518(S *a) {
    if (a->f8) {
        func_004C1FE8(0x42, a->f8 & 0xFF000000FFUL);
    }
    if (a->f4 & 0xFF000000) {
        func_004C1FE8(0x4E, ((D_001A1ED0[2] >> 13) | 0x1000000) | 0x100000000UL);
        func_00403708(0, D_001CFEC0[0xA9], 0, D_001CFEC0[0xA8], a->f4);
        func_004C1FE8(0x4E, 0x1000000 | (D_001A1ED0[2] >> 13));
    }
    if (a->f8) {
        func_004C1FE8(0x42, 0x8000000044UL);
    }
}
