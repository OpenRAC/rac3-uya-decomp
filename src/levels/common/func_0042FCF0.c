#include "common.h"

/* localdecomp:start func_0042FCF0 */
typedef struct { u8 p0[8]; s32 f8; u8 p1[4]; s32 f10; u8 p2[0x15C-0x14]; s32 f15C; u8 p3[4]; s32 f164; u8 p4[4]; s32 f16C; u8 p5[0x17C-0x170]; s32 f17C; } S_396CE8;
extern S_396CE8 D_00142430_00396CE8[];
extern s32 D_001D4CE8_00396CE8;
extern s32 D_001D4CEC_00396CE8;
#define P D_00142430_00396CE8[0]
void func_0042FCF0(void) {
    if (P.f15C != 2) return; if (P.f164 >= 0) return; if (P.f16C != 0 || (P.f8 == 2 && P.f10 != 0)) { P.f17C = 0; D_001D4CE8_00396CE8 = 3; D_001D4CEC_00396CE8 = (D_001D4CEC_00396CE8 & 0x40) | 1; } else { P.f17C = 1; D_001D4CE8_00396CE8 = 1; }
}
/* localdecomp:end func_0042FCF0 */
