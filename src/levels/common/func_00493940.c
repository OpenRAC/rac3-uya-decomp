#include "common.h"

/* localdecomp:start func_00493940 */
extern f32 D_001D9228;
extern void func_004939D0(void);
extern void func_00493B70(void);
extern void func_00494288(void *, s32, s32, s32, s32, s32, f32, f32);

void func_00493940(s32 a, s32 b) {
    func_00494288(func_004939D0, a, b, 0, 1, 1, D_001D9228, 1.0f);
    func_00494288(func_00493B70, a, b, 2, 1, 1, D_001D9228, 1.0f);
}
/* localdecomp:end func_00493940 */
