#include "common.h"

/* localdecomp:start func_0039EF18 */
typedef int Q_39EF18 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_39EF18;
extern void func_004C41E8(void *, void *);
extern void func_0040C0F0(void *, void *, f32);
extern void func_0040BF20(void *, void *, void *);
extern f32 func_004408C0(f32, f32);
extern f32 func_0040CEC8(f32, f32);
extern void func_00440CF8(void *, f32, f32, f32);
extern void func_0040C2D0(void *, void *, void *);
extern s32 func_00440878(s32, s32);
extern u8 *func_003D4768(void *, void *, s32, s32, s32);

void func_0039EF18(u8 *self) {
    V4_39EF18 v[6];
    u8 *s = *(u8 **)(self + 0x68);
    f32 a, b, c;
    u8 *r;
    Q_39EF18 p, q;
    f32 z = 0.0f;
    func_004C41E8(self + 0x10, &v[2]);
    v[3].x = v[2].z;
    v[3].y = v[2].z;
    v[3].z = -(v[2].x + v[2].y);
    func_0040C0F0(&v[0], &v[3], 1.0f);
    func_0040BF20(&v[1], &v[0], &v[2]);
    v[2].w = z;
    v[1].w = z;
    v[0].w = z;
    a = func_004408C0(160.0f, 200.0f);
    b = func_0040CEC8(*(f32 *)(self + 0xF8), a * 0.017453292f);
    a = func_004408C0(0.17453292f, 0.87266463f);
    c = func_004408C0(2.0f, 5.0f);
    func_00440CF8(&v[4], c * 0.016666668f, b, a);
    v[4].w = z;
    func_0040C2D0(&v[4], &v[4], &v[0]);
    *(s32 *)(s + 0xA0) = func_00440878(60, 120);
    func_004C41E8(self + 0x10, &v[5]);
    func_0040C0F0(&v[5], &v[5], 0.2f);
    __asm__("lqc2 %0, %1" : "=j"(p) : "m"(v[5]));
    __asm__("lqc2 %0, %1" : "=j"(q) : "m"(*(V4_39EF18 *)(self + 0x10)));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(q) : "j"(q), "j"(p));
    __asm__("sqc2 %1, %0" : "=m"(v[5]) : "j"(q));
    r = func_003D4768(&v[5], &v[4], 0, 0, 0);
    if (r != 0) {
        *(s32 *)(r + 0xB8) = *(s32 *)(self + 0xB8);
    }
}
/* localdecomp:end func_0039EF18 */
