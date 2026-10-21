#include "common.h"

/* localdecomp:start func_004C1BB0 */
extern void func_004C1BB0(void);
extern u32 D_001D545C;

extern u32 D_001D545C;
extern u32 D_002EE8F0[];
extern s32 D_001E10F0;
extern s32 D_001D66A4;
extern void func_004C1C00(void);

void func_004C1BB0(void) {
    u32 index = D_001D545C;

    if (index >= 0x25) {
        index = 0;
    }
    D_001D66A4 = 0x1E000;
    D_001E10F0 = D_002EE8F0[index];
    func_004C1C00();
}
/* localdecomp:end func_004C1BB0 */
