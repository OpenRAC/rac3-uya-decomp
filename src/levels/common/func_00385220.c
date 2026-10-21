#include "common.h"

/* localdecomp:start func_00385220 */
typedef int Q_385220 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_385220;
extern V4_385220 D_001E2A40;
extern u8 *D_00221284[];
extern s32 D_001D66B0;
extern f32 func_004408C0(f32, f32);
extern f32 func_00440918(f32, f32);
extern f32 func_00440978(void);
extern s32 func_00440878(s32, s32);
extern void func_00440CF8(void *, f32, f32, f32);
extern void func_0040C0F0(void *, void *, f32);
extern u8 *func_0046D1D0(f32, void *, void *, u32, u32, s32, s32, s32, s32, s32, f32);
extern u8 *func_0046D570(f32, void *, s32, f32, u32, s32, s32, void *, s32, s32, s32, s32);
void func_00385220(u8 *obj, V4_385220 *pos, s32 a2, s32 flag) {
    u8 *st = *(u8 **)(obj + 104);
    u8 *r;

    if (*(s32 *)(st + 60) < 2) {
        V4_385220 dir;
        V4_385220 d;
        V4_385220 p;
        f32 a, b, s, sz;
        s32 n;

        a = func_004408C0(-0.95993108f, -1.3962634f);
        b = func_00440978();
        s = func_004408C0(0.0f, 0.5f);
        func_00440CF8(&dir, s * 0.016666668f, b, a);
        {
            Q_385220 x, y, r;
            __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*pos));
            __asm__("lqc2 %0, %1" : "=j"(y) : "m"(D_001E2A40));
            __asm__("vsub.xyz %0, %1, %2" : "=j"(r) : "j"(y), "j"(x));
            __asm__("sqc2 %1, %0" : "=m"(d) : "j"(r));
        }
        func_0040C0F0(&d, &d, 0.15f);
        {
            Q_385220 x, y, r;
            __asm__("lqc2 %0, %1" : "=j"(x) : "m"(d));
            __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*pos));
            __asm__("vadd.xyz %0, %1, %2" : "=j"(r) : "j"(y), "j"(x));
            __asm__("sqc2 %1, %0" : "=m"(*pos) : "j"(r));
        }
        sz = func_004408C0(50000.0f, 80000.0f);
        p.x = pos->x + func_00440918(0.0f, 0.175f);
        p.y = pos->y + func_00440918(0.0f, 0.175f);
        p.z = pos->z + func_00440918(0.0f, 0.175f);
        if (flag) {
            n = func_00440878(10, 20);
            r = func_0046D1D0(sz, &p, &dir, 0x4F5050FF, 0x102434EE, n, 1, -1, -1, 1, 0.5f);
        } else {
            n = func_00440878(25, 60);
            r = func_0046D1D0(sz, &p, &dir, 0x4F5050FF, 0x102434EE, n, 1, -1, -1, 1, 0.5f);
        }
        if (r) {
            r[2] = *D_00221284[0];
        }
    }
    func_0046D570(0.1f, pos, 40, 1.05f, 0x64FFFFFF, 2, 4, &D_001D66B0, 0, 1, 6, 1);
    func_0046D570(0.4f, pos, 30, 2.05f, 0x3C3882F7, 2, 0, &D_001D66B0, 0, 0, 6, 1);
    func_0046D570(0.15f, pos, 40, 1.65f, 0x323882F7, 0, 2, &D_001D66B0, 0, 4, 6, 1);
    func_0046D570(0.5f, pos, 27, 2.35f, 0x3C0045F7, 2, 0, &D_001D66B0, 3, 0, 6, 1);
    func_0046D570(0.3f, pos, 27, 1.75f, 0x1E0045F7, 1, -2, &D_001D66B0, 3, 4, 6, 1);
    if (*(s32 *)(st + 60) < 2) {
        u8 *q;
        q = func_0046D570(0.9f, pos, 10, 0.7f, 0x80141414, 2, 2, &D_001D66B0, 0, 2, 6, 1);
        if (q) q[3] = 68;
        q = func_0046D570(1.7f, pos, 10, 0.7f, 0x80141414, 2, -1, &D_001D66B0, 1, 2, 6, 1);
        if (q) q[3] = 68;
        q = func_0046D570(2.0f, pos, 10, 1.5f, 0x64141414, 2, 1, &D_001D66B0, 1, 2, 6, 1);
        if (q) q[3] = 68;
    }
}
/* localdecomp:end func_00385220 */
