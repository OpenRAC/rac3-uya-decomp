#include "common.h"

/* localdecomp:start func_00437818 */
extern void func_00437818();

typedef struct { f32 x, y, z, w; } V4_3BDAC8;
typedef struct { f32 m[12]; V4_3BDAC8 v; } M_3BDAC8;
typedef int Q_3BDAC8 __attribute__((mode(TI)));
extern void func_0043CE28();
extern void func_0040BE90(f32 *, void *, f32);
extern void func_0040C8A0();
extern void func_0040C9B0();
void func_00437818(u8 *a, s32 n, s32 c, u8 *out) {
    f32 buf[16];
    f32 scale;
    u8 *p, *q;
    s32 i;
    M_3BDAC8 *o;
    Q_3BDAC8 x, y;
    scale = *(f32 *)(a + 0x2C) * 0.0009765625f;
    func_0040C8A0(buf, a + 0xC0);
    func_0043CE28(a, n, c, out);
    o = (M_3BDAC8 *)out;
    for (i = 0; i < n; i++) {
        func_0040C9B0(&o[i], buf, &o[i]);
        func_0040BE90((f32 *)&o[i].v, &o[i].v, scale);
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*(V4_3BDAC8 *)&o[i].v));
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*(V4_3BDAC8 *)(a + 0x10)));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(*(V4_3BDAC8 *)&o[i].v) : "j"(x));
    }

}
/* localdecomp:end func_00437818 */
