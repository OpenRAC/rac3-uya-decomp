#include "common.h"

typedef struct {
    u8 p0[0x34];
    s32 w52;
} S_45AF00;

extern u32 *D_001E10E8;
extern s32 D_001D4CF8;
extern u8 D_001D0560[];
extern S_45AF00 D_001E6E00;
extern s32 D_001EA840[];
extern void func_00402BF0(void);
extern void func_00402D50(void);

void func_0045AF00(u32 *p) {
    D_001E10E8 = p;
    p[0] = 0x30000009;
    D_001E10E8[1] = (D_001D4CF8 + 192) & 0x0FFFFFFF;
    D_001E10E8[2] = 0;
    D_001E10E8[3] = 0x50000009;
    D_001E10E8[4] = 0x30000025;
    D_001E10E8[5] = (u32)D_001D0560;
    D_001E10E8[6] = 0;
    D_001E10E8[7] = 0x50000025;
    D_001E10E8 += 8;
    D_001E6E00.w52++;
    if (D_001EA840[0] != 0) {
        func_00402BF0();
    } else {
        func_00402D50();
    }
    D_001E10E8[0] = 0x70000000;
    D_001E10E8[1] = 0;
    D_001E10E8 += 4;
}
