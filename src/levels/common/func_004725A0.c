#include "common.h"

/* localdecomp:start func_004725A0 */
typedef int Q_4725A0 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_4725A0;
extern s32 D_001D673C;
extern s32 func_0040BAC0(void *);
extern void func_0045E580(void *);
extern s32 func_0040D020(s32, s32, f32);
extern void func_004C6EC8(void *, void *);
extern void func_004C41E8(void *, void *);
extern void func_0040C0F0(void *, void *, f32);

void func_004725A0(u8 *obj)
{
    V4_4725A0 v;
    u8 *s;
    u8 *p;
    if (func_0040BAC0(obj + 0xA) != 0) {
        func_0045E580(obj);
        return;
    }
    s = obj + 0x20;
    p = obj + 0x10;
    *(s32 *)(obj + 4) = func_0040D020(*(s32 *)(s + 0x1C), *(s32 *)(s + 0x18), (f32) * (s16 *)(obj + 0xA) * *(f32 *)(s + 0xC));
    {
        Q_4725A0 x, y;
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*(V4_4725A0 *)(obj + 0x10)));
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*(V4_4725A0 *)(obj + 0x20)));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(*(V4_4725A0 *)(obj + 0x10)) : "j"(x));
    }
    func_004C6EC8(p, p);
    if (D_001D673C == 0) {
        *(f32 *)(s + 8) = *(f32 *)(s + 8) - (f32) * (s16 *)(s + 0x16) * 0.0078125f * 0.000277777785f;
    } else {
        func_004C41E8(p, &v);
        func_0040C0F0(&v, &v, -((f32) * (s16 *)(s + 0x16) * 0.0078125f * 0.000277777785f));
        {
            Q_4725A0 x, y;
            __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*(V4_4725A0 *)(obj + 0x10)));
            __asm__("lqc2 %0, %1" : "=j"(y) : "m"(v));
            __asm__("vadd.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
            __asm__("sqc2 %1, %0" : "=m"(*(V4_4725A0 *)(obj + 0x10)) : "j"(x));
        }
    }
    obj[8] = obj[8] + s[0x14];
    *(f32 *)(obj + 0xC) = *(f32 *)(obj + 0xC) + *(f32 *)(s + 0x10);
}
/* localdecomp:end func_004725A0 */
