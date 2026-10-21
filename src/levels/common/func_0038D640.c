#include "common.h"

/* localdecomp:start func_0038D640 */
typedef int Q_38D640 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_38D640;
extern s32 D_0029EED0[];
extern void func_0038E070(void);
extern s32 func_0040BA90(void *);
extern f32 func_004408C0(f32, f32);
extern u8 *func_00462B40(void *, void *);
extern void func_0040C0F0(void *, void *, f32);
extern void func_0038D7F8(void);
extern void func_004026A0(void *, void *);

void func_0038D640(u8 *a0) {
    V_38D640 v;
    Q_38D640 a, b;
    f32 *t;
    u8 *r, *w, *pa;
    s32 i;
    t = *(f32 **)(a0 + 0x68);
    if (a0[0x20] == 0) {
        func_0038E070();
        a0[0x20] = 1;
        D_0029EED0[0] = 5;
        t[1] = 0.5f;
    }
    if (!func_0040BA90(D_0029EED0) && *(s32 *)(t + 2) == 0) {
        pa = a0 + 0x10;
        for (i = 9; i >= 0; i--) {
            v.x = func_004408C0(-0.3f, 0.3f) * t[1];
            v.y = func_004408C0(-0.3f, 0.3f) * t[1];
            v.z = func_004408C0(-0.3f, 0.3f) * t[1];
            v.w = 0.0f;
            r = func_00462B40(pa, &v);
            if (r) {
                w = r + 0x30;
                func_0040C0F0(&v, &v, 1.0f);
                __asm__("lqc2 %0, %1" : "=j"(a) : "m"(*(V_38D640 *)(a0 + 16)));
                __asm__("lqc2 %0, %1" : "=j"(b) : "m"(v));
                __asm__("vadd.xyz %0, %1, %2" : "=j"(a) : "j"(a), "j"(b));
                __asm__("sqc2 %1, %0" : "=m"(*(V_38D640 *)(r + 0x10)) : "j"(a));
                *(Q_38D640 *)(r + 0x20) = *(Q_38D640 *)(a0 + 0x10);
                *(f32 *)(w + 0xC) = 1.0f;
                *(f32 *)(r + 0x1C) = 0.05f;
                *(f32 *)(r + 0x2C) = 0.25f;
            }
        }
    }
    func_004026A0(func_0038D7F8, a0);
}
/* localdecomp:end func_0038D640 */
