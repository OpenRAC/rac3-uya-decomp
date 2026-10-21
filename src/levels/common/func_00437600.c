#include "common.h"

/* localdecomp:start func_00437600 */
extern void func_0040BE90(f32 *, void *, f32);
extern void func_00437600(u8 *, s32, u8 *);
extern void func_00437600();

typedef struct { f32 x, y, z, w; } V4_3BD9A0;
typedef int Q_3BD9A0 __attribute__((mode(TI)));
extern void func_0043CE28();
extern void func_0040BE90(f32 *, void *, f32);
extern void func_0040C8A0();
extern void func_0040C9B0();
void func_00437600(u8 *a, s32 b, u8 *out) {
    s32 loc;
    f32 buf[16];
    f32 scale;
    Q_3BD9A0 x, y;
    loc = b;
    scale = *(f32 *)(a + 0x2C) * 0.0009765625f;
    func_0043CE28(a, 1, &loc, out);
    func_0040BE90((f32 *)(out + 0x30), out + 0x30, scale);
    func_0040C8A0(buf, a + 0xC0);
    func_0040C9B0(out, buf, out);
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*(V4_3BD9A0 *)(a + 0x10)));
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*(V4_3BD9A0 *)(out + 0x30)));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
    __asm__("sqc2 %1, %0" : "=m"(*(V4_3BD9A0 *)(out + 0x30)) : "j"(x));

}
/* localdecomp:end func_00437600 */
