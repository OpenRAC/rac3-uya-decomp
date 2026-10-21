#include "common.h"

/* localdecomp:start func_003E2638 */
typedef int Q_3E2638 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3E2638;
typedef struct {
    u8 pad0[0x10];
    V4_3E2638 v10;
    V4_3E2638 v20;
    V4_3E2638 v30;
    u8 pad40[0x54];
    s32 w94;
} O_3E2638;
typedef struct {
    u8 pad0[0x20];
    V4_3E2638 v20;
    u8 pad30[0x430];
} E_3E2638;
extern E_3E2638 D_001E2B20[];
extern void func_003E2238(void *, void *);
extern void func_0040BE90(void *, void *, f32);
extern f32 func_0040BEF8(void *, void *);
extern f32 func_0040BF38(void *);
extern f32 func_0040C3F8(f32);

f32 func_003E2638(O_3E2638 *o, f32 f) {
    V4_3E2638 v0;
    V4_3E2638 v1;
    V4_3E2638 v2;
    V4_3E2638 v3;
    V4_3E2638 t40;
    V4_3E2638 t50;
    Q_3E2638 x, y, z;
    E_3E2638 *e = &D_001E2B20[o->w94];
    f32 len;
    f32 ang;

    func_003E2238(o, &v0);
    func_0040BE90(&v1, &e->v20, f);
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(v0));
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(v1));
    __asm__("sqc2 %1, %0" : "=m"(t50) : "j"(x));
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(o->v30));
    __asm__("sqc2 %1, %0" : "=m"(t40) : "j"(x));
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(t50));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(y) : "j"(y), "j"(x));
    __asm__("sqc2 %1, %0" : "=m"(v1) : "j"(y));
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(t40));
    __asm__("lqc2 %0, %1" : "=j"(z) : "m"(v1));
    __asm__("vsub.xyz %0, %1, %2" : "=j"(y) : "j"(z), "j"(x));
    __asm__("sqc2 %1, %0" : "=m"(v2) : "j"(y));
    ang = func_0040BEF8(&v2, &o->v10);
    func_0040BE90(&v3, &o->v10, ang);
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(v2));
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(v3));
    __asm__("vsub.xyz %0, %1, %2" : "=j"(y) : "j"(y), "j"(x));
    __asm__("sqc2 %1, %0" : "=m"(v2) : "j"(y));
    ang = func_0040BEF8(&v2, o);
    len = func_0040BF38(&v2);
    if (len == 0.0f) {
        return 0.0f;
    }
    ang = 1.5707964f - func_0040C3F8(ang / len);
    if (func_0040BEF8(&v2, &o->v20) < 0.0f) {
        ang = -ang;
    }
    return ang;
}
/* localdecomp:end func_003E2638 */
