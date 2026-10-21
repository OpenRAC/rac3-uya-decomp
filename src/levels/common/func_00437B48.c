#include "common.h"

/* localdecomp:start func_00437B48 */
extern s32 D_001E00E0;
extern u32 *D_001E00E4;
typedef struct { u32 w[4]; } T_437B48;
extern T_437B48 *D_001E10E8;
extern s32 D_001D66A8;
extern s32 D_001DFBF4;
extern void func_004A0B88(s32, s32);
extern void func_004A0830(s32);

void func_00437B48(void) {
    u32 *q;
    if (D_001E00E0 == 0) {
        D_001E00E4[0] = 0x10000000;
        D_001E00E4[1] = 0;
        D_001E00E4[2] = 0;
        D_001E00E4[3] = 0;
    } else {
        q = (u32 *)D_001E10E8++;
        D_001E00E4[0] = 0x20000000;
        D_001E00E4[1] = (u32)D_001E10E8;
        D_001E00E4[2] = 0;
        D_001E00E4[3] = 0;
        func_004A0B88(D_001DFBF4, D_001D66A8);
        func_004A0830(D_001DFBF4);
        ((u32 *)D_001E10E8)[0] = 0x20000000;
        ((u32 *)D_001E10E8)[1] = (u32)(D_001E00E4 + 4);
        ((u32 *)D_001E10E8)[2] = 0;
        ((u32 *)D_001E10E8)[3] = 0;
        D_001E10E8++;
        q[0] = 0x20000000;
        q[1] = (u32)D_001E10E8;
        q[2] = 0;
        q[3] = 0;
    }
}
/* localdecomp:end func_00437B48 */
