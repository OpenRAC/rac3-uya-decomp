#include "common.h"

/* localdecomp:start func_0035BDC8 */
typedef int Q_35BDC8 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_35BDC8;
typedef struct {
    u8 b0;
    u8 b1;
    u8 pad[238];
} S_35BDC8;
extern V4_35BDC8 D_001E2A40;
extern u8 D_001425C0[];
extern S_35BDC8 D_002C5640[];
extern s32 D_001D66B0;
extern f32 func_0040C490(f32, f32);
extern f32 func_004408C0(f32, f32);
extern f32 func_00440918(f32, f32);
extern f32 func_0040CEC8(f32, f32);
extern s32 func_00440878(s32, s32);
extern void func_00440CF8(void *, f32, f32, f32);
extern void func_0040C0F0(void *, void *, f32);
extern void func_00466F98(void *, void *, s32, s32, s32, s32, f32, f32, f32, f32, f32);
extern void func_0046CF70(void *, void *, s32, f32);
extern void func_0046D570(void *, s32, u32, s32, s32, void *, s32, s32, s32, s32, f32, f32);
static __inline__ void vsubA_35BDC8(V4_35BDC8 *d, V4_35BDC8 *a, V4_35BDC8 *b) {
    Q_35BDC8 x, y, z;
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*a));
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*b));
    __asm__("vsub.xyz %0, %1, %2" : "=j"(z) : "j"(x), "j"(y));
    __asm__("sqc2 %1, %0" : "=m"(*d) : "j"(z));
}
void func_0035BDC8(V4_35BDC8 *obj) {
    V4_35BDC8 v;
    V4_35BDC8 vel;
    V4_35BDC8 pos;
    f32 ang;
    f32 e;
    f32 r;
    f32 d;
    s32 k;
    s32 n;
    s32 m;
    f32 big;

    vsubA_35BDC8(&v, &D_001E2A40, obj);
    ang = func_0040C490(v.x, v.y);
    for (n = 7; n >= 0; n--) {
        e = func_004408C0(0.5f, 1.0f);
        k = (s32)func_00440918(1.0f, 2.0f);
        func_004408C0(0.05f, 0.2f);
        big = 210000.0f;
        r = func_004408C0(0.0f, 1.3962634f);
        d = func_0040CEC8(ang, func_00440918(0.0f, 1.3962634f));
        func_00440CF8(&vel, e * 0.016666668f, d, r);
        pos.x = obj->x + func_00440918(0.0f, 0.1f);
        pos.y = obj->y + func_00440918(0.0f, 0.1f);
        pos.z = obj->z + func_00440918(0.0f, 0.1f);
        func_00466F98(&pos, &vel, 30, 127, 0x7F7F7F, k, func_004408C0(0.05f, 0.2f) * big, 500.0f, 1.0f, 0.0f, 1.0f);
    }
    if ((D_002C5640 + D_001425C0[47])->b1 >= 2) {
        vsubA_35BDC8(&vel, &D_001E2A40, obj);
        func_0040C0F0(&vel, &vel, func_004408C0(0.05f, 0.1f));
        for (m = 7; m >= 0; m--) {
            vel.x += func_004408C0(-0.03f, 0.03f);
            vel.y += func_004408C0(-0.03f, 0.03f);
            vel.z += func_004408C0(0.0f, 0.03f);
            func_0046CF70(obj, &vel, func_00440878(25, 40), 0.0040555559f);
        }
    }
    if ((D_002C5640 + D_001425C0[47])->b1 >= 3) {
        func_0046D570(obj, 40, 0x64FFFFFF, 2, 4, &D_001D66B0, 0, 1, 6, 1, 0.1f, 1.05f);
        func_0046D570(obj, 30, 0x3C3882F7, 2, 0, &D_001D66B0, 0, 0, 6, 1, 0.4f, 2.05f);
        func_0046D570(obj, 40, 0x323882F7, 0, 2, &D_001D66B0, 0, 4, 6, 1, 0.15f, 1.65f);
        func_0046D570(obj, 27, 0x3C0045F7, 2, 0, &D_001D66B0, 3, 0, 6, 1, 0.5f, 2.35f);
        func_0046D570(obj, 27, 0x1E0045F7, 1, -2, &D_001D66B0, 3, 4, 6, 1, 0.3f, 1.75f);
    }
}
/* localdecomp:end func_0035BDC8 */
