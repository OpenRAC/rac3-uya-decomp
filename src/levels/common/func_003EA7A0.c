#include "common.h"

/* localdecomp:start func_003EA7A0 */
typedef int Q_3EA7A0 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3EA7A0;
extern u8 D_001E2AC0[];
extern u8 D_001E2B20[];
extern void func_0040C0F0(void *, void *, f32);
extern f32 func_0040BEF8(void *, void *);
extern f32 func_0040C3F8(f32);
extern f32 func_003F1438(void *, f32, f32, f32, f32, f32);
extern void func_0040BF20(void *, void *, void *);
extern void func_0040CCA0(void *, void *, void *, f32);
typedef struct { u8 pad[0x20]; V4_3EA7A0 f20; } E_3EA7A0;
#define F_(p, o) (*(f32 *)((u8 *)(p) + (o)))
void func_003EA7A0(u8 *p) {
    V4_3EA7A0 tmp, v1, v2;
    Q_3EA7A0 a, b, c;
    u8 *t, *ent, *q, *qs, *e2;
    f32 g, f21;
    ent = D_001E2AC0 + *(s32 *)(p + 0x94) * 0x460;
    __asm__("lqc2 %0, %1" : "=j"(b) : "m"(*(V4_3EA7A0 *)(p + 0x30)));
    q = *(u8 **)(p + 0x70);
    qs = q + 0x30;
    tmp = *(V4_3EA7A0 *)(ent + 0x190);
    e2 = ent + 0x150;
    tmp.z += F_(q, 0x8C);
    __asm__("lqc2 %0, %1" : "=j"(a) : "m"(tmp));
    __asm__("vsub.xyz %0, %1, %2" : "=j"(c) : "j"(a), "j"(b));
    __asm__("sqc2 %1, %0" : "=m"(v1) : "j"(c));
    func_0040C0F0(&v1, &v1, 1.0f);
    g = func_0040C3F8(func_0040BEF8(&v1, p));
    g = 1.5707964f - g;
    if (*(s32 *)(e2 + 0x100) == 0x24) {
        F_(q, 0x30) += 0.017f;
        if (F_(q, 0x30) > 1.0f) F_(q, 0x30) = 1.0f;
        f21 = g * F_(q, 0x30);
    } else {
        f21 = func_003F1438(qs, 0.0f, g, 0.02f, 0.175f, 0.0f);
    }
    func_0040BF20(&v2, &v1, p + 0x40);
    func_0040CCA0(p, p + 0x40, &v2, f21);
    func_0040C0F0(p + 0x40, p, 1.0f);
    t = D_001E2B20 + *(s32 *)(p + 0x94) * 0x460;
    *(V4_3EA7A0 *)p = *(V4_3EA7A0 *)(p + 0x40);
    func_0040BF20(p + 0x10, p, t + 0x20);
    func_0040C0F0(p + 0x10, p + 0x10, 1.0f);
    func_0040BF20(p + 0x20, p + 0x10, p);
}
/* localdecomp:end func_003EA7A0 */
