#include "common.h"

/* localdecomp:start func_003D2870 */
typedef int Q_3D2870 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_3D2870;
typedef struct {
    u8 pad0[0x10];
    V_3D2870 pos;
} O_3D2870;
typedef struct {
    u8 pad0[0x140];
    f32 x140;
    f32 x144;
} G_3D2870;
extern s32 D_001DDBCC;
extern G_3D2870 D_001E2900;
extern void func_004A7200(s32, s32, void *);
extern f32 func_004408C0(f32, f32);
extern f32 func_00440978(void);
extern f32 func_00440918(f32, f32);
extern void func_00440CF8(void *, f32, f32, f32);
extern s32 func_00440878(s32, s32);
extern void func_004632D8(void *, void *, u32, u32, s32, f32);
extern f32 func_0040C490(f32, f32);
extern f32 func_0040CEC8(f32, f32);
extern f32 func_0040C3C8(f32);
extern f32 func_0040C3E0(f32);
extern void func_00471248(void *, void *, s32);
extern void func_003D46A8(void *, s32, s32, s32, s32, f32, f32);
extern void func_00300250(void *, void *, void *);
extern void func_003D2CF0(void *);
extern void func_00436220(void *);
static __inline__ void polar_3D2870(V_3D2870 *v, f32 ang, f32 len) {
    v->x = func_0040C3C8(ang) * len;
    v->y = func_0040C3E0(ang) * len;
    v->z = 0.0f;
}
void func_003D2870(O_3D2870 *o) {
    V_3D2870 a;
    V_3D2870 b;
    s32 i, j, k;

    if (o != 0) {
        func_004A7200(1, 0, o);
    }
    for (i = 0; i < 25 - D_001DDBCC; i++) {
        f32 r, s;
        r = func_004408C0(0.0f, 0.370000005f);
        s = func_00440978();
        func_00440CF8(&b, r, s, func_00440978());
        b.z += func_004408C0(0.349999994f, 0.600000024f);
        {
            Q_3D2870 q1, q2;
            __asm__("lqc2 %0, %1" : "=j"(q2) : "m"(o->pos));
            __asm__("lqc2 %0, %1" : "=j"(q1) : "m"(b));
            __asm__("vadd.xyz %0, %0, %1" : "+j"(q1) : "j"(q2));
            __asm__("sqc2 %1, %0" : "=m"(b) : "j"(q1));
        }
        r = func_004408C0(0.00250000018f, 0.0200000014f);
        s = func_00440978();
        func_00440CF8(&a, r, s, func_00440978());
        func_004632D8(&b, &a, 0x4F7F7F7F, 0x00202020, func_00440878(30, 57), 150000.0f);
    }
    for (j = 0; j < 30 - D_001DDBCC; j++) {
        f32 ang, spd;
        ang = func_0040C490(D_001E2900.x140 - o->pos.x, D_001E2900.x144 - o->pos.y);
        func_00440918(1.0f, 2.0f);
        a.x = o->pos.x + func_00440918(0.0f, 0.150000006f);
        a.y = o->pos.y + func_00440918(0.0f, 0.150000006f);
        a.z = o->pos.z + func_00440918(0.0f, 0.150000006f);
        spd = func_004408C0(3.0f, 7.0f);
        polar_3D2870(&b, func_0040CEC8(ang, func_00440918(0.0f, 2.61799383f)), spd * 0.0166666675f);
        b.z = func_004408C0(5.0f, 10.0f) * 0.0166666675f;
        func_00471248(&a, &b, 170);
    }
    func_003D46A8(o, 78, 79, 10, 1, 1.5f, 1.20000005f);
    for (k = 0; k < 10; k++) {
        f32 r, s;
        r = func_004408C0(0.0f, 0.349999994f);
        s = func_00440978();
        func_00440CF8(&b, r, s, func_00440978());
        b.z += 0.25f;
        {
            Q_3D2870 q1, q2;
            __asm__("lqc2 %0, %1" : "=j"(q2) : "m"(o->pos));
            __asm__("lqc2 %0, %1" : "=j"(q1) : "m"(b));
            __asm__("vadd.xyz %0, %0, %1" : "+j"(q1) : "j"(q2));
            __asm__("sqc2 %1, %0" : "=m"(b) : "j"(q1));
        }
        func_00440CF8(&a, func_004408C0(0.0500000045f, 0.100000009f), func_00440978(), 1.22173047f);
        a.z = func_004408C0(3.0f, 5.0f) * 0.0166666675f;
        func_00300250(o, &b, &a);
    }
    D_001DDBCC--;
    func_003D2CF0(o);
    func_00436220(o);
}
/* localdecomp:end func_003D2870 */
