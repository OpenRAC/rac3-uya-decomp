#include "common.h"

/* localdecomp:start func_0044E3A8 */
extern f32 func_0040BF38(s32 a);
extern void func_0040C0F0(s32 a, s32 b, f32 x);
extern void func_0040BE90(f32 *, void *, f32);
extern void func_0040C0F0(s32, s32, f32);
extern void func_0044E3A8(s32, f32 *, s32);

extern void func_0040BF20(f32 *, f32 *, s32);
extern void func_0040CB80(f32 *, f32 *);
extern void func_0040C960(s32, f32 *, s32);
extern void func_0040BCB8(s32, f32 *, s32);
void func_0044E3A8(s32 a, f32 *unused, s32 c) {
    f32 m[12];
    f32 b[4];
    f32 v[4];
    f32 r;
    ((void (*)(f32 *, f32))func_0040C0F0)(v, 1.0f);
    func_0040BF20(b, v, a + 0x20);
    ((void (*)(f32 *, f32 *, f32))func_0040BE90)(b, b, 0.5f);
    r = func_0040BF38((s32)b);
    r = 1.0f - r * r;
    __asm__("sqrt.s %0, %1" : "=f"(r) : "f"(r));
    b[3] = -r;
    func_0040CB80(b, m);
    func_0040C960(a, m, a);
    if (c) func_0040BCB8(c, m, 0x30);
}
/* localdecomp:end func_0044E3A8 */
