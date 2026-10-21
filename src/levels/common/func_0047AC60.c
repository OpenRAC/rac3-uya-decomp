#include "common.h"

/* localdecomp:start func_0047AC60 */
extern void *D_002E9FF8[];
extern s32 D_001D6694;
extern s32 D_001A1ED4[];
extern s32 D_001D4BC4;
extern void func_004C2488(void *a0, s32 a1, s32 a2);
extern void func_004035F8(s32 a0, s32 a1, s32 a2, s32 a3);
void func_0047AC60(void) {
    void *p = D_002E9FF8[0];
    if (p != 0 && D_001D6694 == 3) {
        func_004C2488(p, D_001A1ED4[0], D_001D4BC4 << 11);
        func_004035F8(0, 0, 0, 96);
    }
}
/* localdecomp:end func_0047AC60 */
