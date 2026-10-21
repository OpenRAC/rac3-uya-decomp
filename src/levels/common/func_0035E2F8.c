#include "common.h"

/* localdecomp:start func_0035E2F8 */
typedef int Q_35E2F8 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_35E2F8;
typedef struct { u8 b0, b1, b2, b3; } P_35E2F8;
typedef struct { u8 pad0; u8 b1; u8 pad2[238]; } E_35E2F8;
typedef struct { u8 pad[87]; u8 b87; } G_35E2F8;
typedef struct { u8 pad[104]; void *p104; } O_35E2F8;

extern E_35E2F8 D_002C5640[];
extern u8 *D_00221118[];
extern G_35E2F8 D_001425C0;
extern V4_35E2F8 D_001A4EC0;
extern f32 func_0040BF38(void *);
extern void func_0040C0F0(void *, void *, f32);
extern f32 func_00440918(f32, f32);
extern f32 func_004408C0(f32, f32);
extern void func_0040BE90(void *, void *, f32);
extern s32 func_00440878(s32, s32);
extern s32 func_0013D3E0(void);
extern P_35E2F8 *func_00466F98(void *, void *, s32, s32, s32, s32, f32, f32, f32, f32, f32);

void func_0035E2F8(O_35E2F8 *obj, V4_35E2F8 a, V4_35E2F8 b) {
    V4_35E2F8 v32;
    V4_35E2F8 pos;
    V4_35E2F8 step;
    f32 len;
    f32 t;
    s32 n;
    s32 i;
    s32 r;
    s32 cnt;
    s32 size;
    s32 color;
    u8 lv;
    E_35E2F8 *e;
    P_35E2F8 *p;

    len = func_0040BF38(obj->p104);
    n = len / 0.1f;
    pos = b;
    {
        Q_35E2F8 x, y, d;
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(a));
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(b));
        __asm__("vsub.xyz %0, %1, %2" : "=j"(d) : "j"(x), "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(step) : "j"(d));
    }
    func_0040C0F0(&step, &step, len / (f32)n);
    for (i = 0; i < n - 2; i++) {
        r = func_00440918(1.0f, 3.0f);
        t = func_004408C0(0.1f, 0.2f);
        func_0040BE90(&v32, &D_001A4EC0, -(t * 0.016666668f));
        cnt = func_00440878(3, 6);
        if (func_0013D3E0() & 2) {
            size = 64;
            color = 0x4080FF;
        } else {
            size = 96;
            color = 0x4080FF;
        }
        e = &D_002C5640[D_001425C0.b87];
        lv = e->b1;
        if (lv >= 3) {
            if (func_0013D3E0() & 2) {
                size = 64;
                color = 0x407FFF;
            } else {
                size = 96;
                color = 0x4040FF;
            }
        } else if (lv == 2) {
            if (func_0013D3E0() & 2) {
                size = 64;
                color = 0x4080FF;
            } else {
                size = 96;
                color = 0x4080FF;
            }
        } else if (lv == 1) {
            if (func_0013D3E0() & 2) {
                size = 64;
                color = 0x407F7F;
            } else {
                size = 96;
                color = 0x40AFAF;
            }
        }
        p = func_00466F98(&pos, &v32, cnt, size, color, r, 63000.004f, 10000.0f, 1.0f, 0.0f, 0.0f);
        {
            Q_35E2F8 x, y, d;
            __asm__("lqc2 %0, %1" : "=j"(x) : "m"(pos));
            __asm__("lqc2 %0, %1" : "=j"(y) : "m"(step));
            __asm__("vadd.xyz %0, %1, %2" : "=j"(d) : "j"(x), "j"(y));
            __asm__("sqc2 %1, %0" : "=m"(pos) : "j"(d));
        }
        if (p != 0) {
            p->b2 = D_00221118[23][0];
            if (size == 64) {
                p->b3 = 72;
            } else {
                p->b3 = 68;
            }
        }
    }
}
/* localdecomp:end func_0035E2F8 */
