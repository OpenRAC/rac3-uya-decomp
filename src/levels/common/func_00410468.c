#include "common.h"

/* localdecomp:start func_00410468 */
extern void func_0040DBE0(f32, f32, f32, f32, s32, s32, s32, s32, s32, unsigned long, f32, f32);

extern void func_0040DBE0(f32, f32, f32, f32, s32, s32, s32, s32, s32, unsigned long, f32, f32);
void func_00410468(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, f32 p) {
    func_0040DBE0((f32)a0, (f32)a1, p, p, a2, a3, a4, 1, 0, 0x80000000, 0.0f, 0.0f);
}
/* localdecomp:end func_00410468 */
