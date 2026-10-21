#include "common.h"

/* localdecomp:start func_0041A2E0 */
typedef struct {
    u8 pad0[108];
    s32 x6C;
    u8 pad70[12];
    s32 x7C;
    u8 pad80[16];
} Entry_0041A2E0;

extern Entry_0041A2E0 D_002E6110[];
extern void func_0041A170(s32, s32, s32, s32, s32, s32, s32);
extern void func_0041A278(Entry_0041A2E0 *);

void func_0041A2E0(void)
{
    s32 i;

    for (i = 0; i < 13; i++) {
        func_0041A170(i, 0xFFFF, 0, 0, 0, 0, 1);
        D_002E6110[i].x7C = 0;
        D_002E6110[i].x6C = -6;
        func_0041A278(&D_002E6110[i]);
    }
}
/* localdecomp:end func_0041A2E0 */
