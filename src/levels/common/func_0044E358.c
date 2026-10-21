#include "common.h"

/* localdecomp:start func_0044E358 */
extern void func_0040BE90(f32 *, void *, f32);

extern void func_0040BE90(f32 *, void *, f32);
extern void func_0044E3A8(s32, f32 *, s32);
void func_0044E358(s32 a, s32 b, s32 c) {
    f32 buf[4];
    ((void (*)(f32 *, f32))func_0040BE90)(buf, -1.0f);
    func_0044E3A8(a, buf, c);
}
/* localdecomp:end func_0044E358 */
