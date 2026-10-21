#include "common.h"

/* localdecomp:start func_004366B0 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_4366B0;
typedef int Q_4366B0 __attribute__((mode(TI)));
extern void func_0040C8E0(void *, void *);
extern void func_0040C2F8(void *, void *, void *);
extern void func_0040BE90(void *, void *, f32);

void func_004366B0(u8 *obj, s32 idx, V_4366B0 *pos, f32 a, f32 b)
{
    u8 *s;
    V_4366B0 m[4];
    V_4366B0 v;
    f32 k;

    s = *(u8 **)(obj + 0x98);
    if (idx < (*(s32 *)(s + 4) >> 5)) {
        k = 1024.0f / *(f32 *)(obj + 0x2C);
        s += idx * 32 + 16;
        func_0040C8E0(m, obj + 0xC0);
        {
            Q_4366B0 x, y;
            __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*(V_4366B0 *)(obj + 0x10)));
            __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*pos));
            __asm__("vsub.xyz %0, %0, %1" : "+j"(x) : "j"(y));
            __asm__("sqc2 %1, %0" : "=m"(v) : "j"(x));
        }
        func_0040C2F8(&v, &v, m);
        func_0040BE90(&v, &v, k);
        *(V_4366B0 *)(s + 0x10) = v;
        *(f32 *)(s + 4) = b * k;
        *(f32 *)(s + 0x1C) = a * k;
    }
}
/* localdecomp:end func_004366B0 */
