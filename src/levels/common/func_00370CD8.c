#include "common.h"

/* localdecomp:start func_00370CD8 */
typedef int Q_370CD8 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_370CD8;
typedef struct {
    u8 pad0[724];
    s32 i724;
} S_370CD8;
typedef struct {
    u8 pad0[16];
    V4_370CD8 pos;
    u8 pad32[72];
    S_370CD8 *p104;
} O_370CD8;
extern V4_370CD8 D_001E2A40;
extern int D_001D66B0;
extern f32 func_004408C0(f32, f32);
extern void func_0040C0F0(void *, void *, f32);
extern s32 func_00440878(s32, s32);
extern void func_0046CF70(void *, void *, s32, f32);
extern void func_00440B30(void *, f32, f32);
extern void func_004708F8(void *, void *, s32, s32, s32, s32, s32, f32, f32, f32, f32);
extern void func_00467DA8(f32, void *, s32, f32, s32, s32, s32, void *, f32, s32);
extern void func_0046D570(f32, void *, s32, f32, s32, s32, s32, void *, s32, s32, s32, s32);
void func_00370CD8(O_370CD8 *obj, V4_370CD8 *dir) {
    V4_370CD8 tmp;
    V4_370CD8 t32;
    Q_370CD8 x, y;
    s32 lvl = obj->p104->i724;
    s32 i;
    s32 j;
    s32 c0, c2, c4, c7;
    V4_370CD8 *p, *q;

    if (lvl < 2) {
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*dir));
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(D_001E2A40));
        __asm__("vsub.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(tmp) : "j"(x));
        {
            V4_370CD8 *v = &tmp;
            func_0040C0F0(v, v, func_004408C0(0.1f, 0.2f));
        }
        for (j = 0; j < 15; j++) {
            tmp.x += func_004408C0(-0.05f, 0.05f);
            tmp.y += func_004408C0(-0.05f, 0.05f);
            tmp.z += func_004408C0(-0.05f, 0.05f);
            func_0046CF70(&obj->pos, &tmp, func_00440878(25, 40), 0.004055556f);
        }
        return;
    }
    c0 = 0x80804020;
    c7 = 0xFF0000;
    c2 = 0xBF804020;
    c4 = 0xBF604020;
    if (lvl >= 4) {
        c0 = 0x80204080;
        c7 = 255;
        c2 = 0xBF2040FF;
        c4 = 0xBF2040FF;
    }
    p = &tmp;
    for (i = 0; i < 10; i++) {
        func_00440B30(&tmp, 0.083333336f, 0.16666667f);
        func_004708F8(&obj->pos, &tmp, func_00440878(15, 25), c0, c7, 0, 0, 0.1f, 0.25f, 0.9f, 0.5f);
        q = &t32;
    }
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(obj->pos));
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(D_001E2A40));
    __asm__("vsub.xyz %0, %1, %2" : "=j"(y) : "j"(y), "j"(x));
    __asm__("sqc2 %1, %0" : "=m"(t32) : "j"(y));
    func_0040C0F0(q, q, 0.4f);
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(t32));
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(obj->pos));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
    __asm__("sqc2 %1, %0" : "=m"(tmp) : "j"(x));
    func_00467DA8(3.5f, p, 14, 0.1f, c2, 2, 1, &D_001D66B0, 0.0f, 1);
    func_00467DA8(2.5f, p, 14, 0.1f, c4, 2, -1, &D_001D66B0, 0.0f, 1);
    func_00467DA8(1.75f, p, 14, 0.1f, 0xC0FFFFFF, 2, 1, &D_001D66B0, 0.0f, 1);
    func_00467DA8(1.25f, p, 14, 0.1f, 0xB0FFFFFF, 2, -1, &D_001D66B0, 0.0f, 1);
    func_0046D570(0.9f, p, 20, 0.7f, 0x46787878, 2, 2, &D_001D66B0, 0, 2, 6, 1);
    func_0046D570(1.7f, p, 20, 0.7f, 0x46787878, 2, -1, &D_001D66B0, 1, 2, 6, 1);
    func_0046D570(2.0f, p, 20, 1.5f, 0x2D787878, 2, 1, &D_001D66B0, 1, 2, 6, 1);
}
/* localdecomp:end func_00370CD8 */
