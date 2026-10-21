#include "common.h"

/* localdecomp:start func_00401BB0 */
typedef int Q_401BB0 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_401BB0;
extern V_401BB0 D_001E2A40;
extern f32 D_001E7820[];
extern s32 D_001D4BC0;
extern s32 D_001D4BC4;
extern void func_0040BE90(void *, void *, f32);
extern void func_0040C2F8(void *, void *, void *);
void func_00401BB0(V_401BB0 *a, f32 *px, f32 *py) {
    V_401BB0 v;
    Q_401BB0 x, y;
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(D_001E2A40));
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*a));
    __asm__("vsub.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
    __asm__("sqc2 %1, %0" : "=m"(v) : "j"(x));
    func_0040BE90(&v, &v, 1024.0f);
    v.w = 1.0f;
    func_0040C2F8(&v, &v, (u8 *)&D_001E2A40 - 0x100);
    func_0040BE90(&v, &v, D_001E7820[0] / v.w);
    *px = v.x + (f32)(D_001D4BC0 >> 1);
    *px = *px / (f32)D_001D4BC0;
    *py = v.y + (f32)(D_001D4BC4 >> 1);
    *py = *py / (f32)D_001D4BC4;
}
/* localdecomp:end func_00401BB0 */
