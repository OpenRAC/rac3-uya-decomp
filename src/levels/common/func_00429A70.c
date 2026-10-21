#include "common.h"

/* localdecomp:start func_00429A70 */
extern u32 D_001E10F0;

typedef struct {
    u8 pad0[0x6C];
    u32 f6C;
    u8 pad1[0x20];
    u32 slots[1];
} T_958A0;

extern T_958A0 D_001E6E00[];
extern u32 D_001EA9D0[];
extern u32 D_001E10F0;
extern void func_00429740(void);

void func_00429A70(s32 a0) {
    u32 value = D_001E6E00[0].slots[a0];

    D_001E6E00[0].f6C = value;
    func_00429740();
    D_001E6E00[0].f6C = D_001EA9D0[0] + D_001E10F0;
}
/* localdecomp:end func_00429A70 */
