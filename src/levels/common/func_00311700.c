#include "common.h"

/* localdecomp:start func_00311700 */
typedef int Q_311700 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_311700;
extern V_311700 D_001E2AC0;
extern f32 func_0040BF38(void *);
extern f32 func_004408C0(f32, f32);
extern void func_0040C0F0(void *, void *, f32);
extern void func_0040C188(void *, void *, f32);
extern s32 func_00440878(s32, s32);
extern void func_002FB638(void *, void *, s32, s32, s32, s32);
extern f32 func_00440978(void);
extern void func_00440CF8(void *, f32, f32, f32);
extern s32 func_0013D3E0(void);
extern void func_0040C2D0(void *, void *, void *);
void func_00311700(u8 *obj, V_311700 *pos) {
    V_311700 t0, t1, t2;
    Q_311700 a, b, c, d, e, g;
    f32 len, el, az;
    s32 i;
    s32 flag;
    s32 r;
    __asm__("lqc2 %0, %1" : "=j"(a) : "m"(D_001E2AC0));
    __asm__("lqc2 %0, %1" : "=j"(b) : "m"(*pos));
    __asm__("vsub.xyz %0, %1, %2" : "=j"(c) : "j"(a), "j"(b));
    __asm__("sqc2 %1, %0" : "=m"(t0) : "j"(c));
    len = func_0040BF38(&t0);
    *(Q_311700 *)&t2 = 0;
    t2.x = func_004408C0(-1.0f, 1.0f);
    t2.y = func_004408C0(-1.0f, 1.0f);
    t2.z = func_004408C0(-1.0f, 1.0f);
    t0.z += len * 0.5f;
    t1 = t2;
    func_0040C0F0(&t1, &t1, len / 5.0f * 0.016666668f);
    func_0040C0F0(&t0, &t0, len * 2.0f * 0.016666668f);
    __asm__("lqc2 %0, %1" : "=j"(d) : "m"(t1));
    __asm__("lqc2 %0, %1" : "=j"(e) : "m"(t0));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(g) : "j"(d), "j"(e));
    __asm__("sqc2 %1, %0" : "=m"(t1) : "j"(g));
    func_0040C188(&t1, &t1, 0.16666667f);
    func_002FB638(pos, &t1, func_00440878(60, 90), 0, 0, 0);
    for (i = 8; i >= 0; i--) {
        el = func_004408C0(0.2617994f, 1.3089969f);
        az = func_00440978();
        func_00440CF8(&t2, func_004408C0(8.0f, 12.0f) * 0.016666668f, az, el);
        t2.z += 0.0500000045f;
        flag = 0;
        if (func_0013D3E0() % 3 == 0) {
            flag = 1;
        }
        func_0040C2D0(&t2, &t2, obj + 0xC0);
        func_002FB638(pos, &t2, func_00440878(60, 90), flag, 0, 0);
    }
}
/* localdecomp:end func_00311700 */
