#include "common.h"

/* localdecomp:start func_004E9A68 */
extern void func_0050D6D0(s32, s32);
extern void func_0050D640(s32, s32, f32);
extern void func_0050D5B0(s32, s32);
extern void func_0050D530(s32, s32, f32);
void func_004E9A68(s32 a0, s32 a1, f32 f12, f32 f13) {
    if (a1 != 0) {
        func_0050D6D0(a0, a0);
        func_0050D640(a0, a0, f13);
    } else {
        func_0050D5B0(a0, a0);
        func_0050D530(a0, a0, f13);
    }
}
/* localdecomp:end func_004E9A68 */
