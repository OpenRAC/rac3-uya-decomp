#include "common.h"

typedef int s128 __attribute__((mode(TI)));

typedef struct {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} __attribute__((aligned(16))) S_38C110v;

extern void func_0040C658(s128 *, S_38C110v *);
extern void func_0040C9B0(s128 *, void *, s128 *);
extern void func_0040BE90(s128 *, s128 *, f32);
extern void func_0038B628(s128 *, f32, f32, f32, s32, f32, s32, s32);

void func_0038C110(S_38C110v *a0, void *a1, s32 a2, s32 a3, f32 f12, f32 f13, f32 f14, f32 f15, f32 f16, f32 f17) {
    S_38C110v v;
    s128 m1[4];
    s128 m2[4];

    v.x = 0.0f;
    v.y = 0.0f;
    v.z = f12;
    v.w = 1.0f;
    func_0040C658(m1, &v);
    func_0040C9B0(m2, a1, m1);
    func_0040BE90(&m2[0], &m2[0], f13);
    func_0040BE90(&m2[1], &m2[1], f13);
    func_0040BE90(&m2[2], &m2[2], f13);
    *(S_38C110v *)&m2[3] = *a0;
    func_0038B628(m2, f17, f14, f15, a2, f16, a3, 1);
}
