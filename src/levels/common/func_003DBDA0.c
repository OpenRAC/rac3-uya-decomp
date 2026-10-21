#include "common.h"

/* localdecomp:start func_003DBDA0 */
typedef int Q_3DBDA0 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3DBDA0;
typedef struct { u8 pad[108]; f32 f6C; u8 pad2[240 - 112]; } E_3DBDA0;
extern V4_3DBDA0 D_001E2A40;
extern u8 D_00142657[];
extern E_3DBDA0 D_002C5640[];
extern s32 D_001D66B0;
extern f32 func_0040C490(f32, f32);
extern f32 func_0040CEC8(f32, f32);
extern void func_00443648(void *, void *, s32, f32, f32, f32, s32, s32, s32);
extern f32 func_004408C0(f32, f32);
extern f32 func_00440918(f32, f32);
extern void func_00440CF8(void *, f32, f32, f32);
extern void *func_00466F98(void *, void *, s32, s32, s32, s32, f32, f32, f32, f32, f32);
extern void func_0046D570(void *, s32, u32, s32, s32, void *, s32, s32, s32, s32, f32, f32);
void func_003DBDA0(void *obj, V4_3DBDA0 *pos) {
    V4_3DBDA0 d;
    V4_3DBDA0 dir;
    V4_3DBDA0 p;
    f32 ang;
    s32 i;

    {
        Q_3DBDA0 x, y, r;
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(D_001E2A40));
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*pos));
        __asm__("vsub.xyz %0, %1, %2" : "=j"(r) : "j"(x), "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(d) : "j"(r));
    }
    ang = func_0040C490(d.x, d.y);
    func_00443648(obj, pos, 0x08110000, 1.25f, (D_002C5640 + D_00142657[0])->f6C, 1.0f, 0, 1, 0);
    for (i = 0; i < 4; i++) {
        f32 sp, a, b, sz;
        s32 n;
        sp = func_004408C0(0.5f, 1.0f);
        n = (s32)func_00440918(1.0f, 2.0f);
        sz = func_004408C0(0.05f, 0.2f) * 210000.0f;
        a = func_004408C0(0.0f, 1.3962634f);
        b = func_0040CEC8(ang, func_00440918(0.0f, 1.3962634f));
        func_00440CF8(&dir, sp * 0.016666668f, b, a);
        p.x = pos->x + func_00440918(0.0f, 0.1f);
        p.y = pos->y + func_00440918(0.0f, 0.1f);
        p.z = pos->z + func_00440918(0.0f, 0.1f);
        sz = func_004408C0(0.05f, 0.2f) * 210000.0f;
        func_00466F98(&p, &dir, 30, 127, 0x20207F, n, sz, 500.0f, 1.0f, 0.0f, 1.0f);
    }
    func_0046D570(pos, 80, 0x64A0A0FF, 2, 4, &D_001D66B0, 0, 1, 6, 1, 0.1f, 1.05f);
    func_0046D570(pos, 60, 0x3C0A32F7, 2, 0, &D_001D66B0, 0, 0, 6, 1, 0.4f, 2.05f);
    func_0046D570(pos, 80, 0x320A32F7, 0, 2, &D_001D66B0, 0, 4, 6, 1, 0.15f, 1.65f);
    func_0046D570(pos, 54, 0x3C0014F7, 2, 0, &D_001D66B0, 3, 0, 6, 1, 0.5f, 2.35f);
    func_0046D570(pos, 54, 0x1E0014F7, 1, -2, &D_001D66B0, 3, 4, 6, 1, 0.3f, 1.75f);
}
/* localdecomp:end func_003DBDA0 */
